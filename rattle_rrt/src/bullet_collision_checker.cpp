/* A collision-checking module, using bullet.

Credit to Abhi Cauligi of Stanford ASL.
*/

#include <bullet_collision_checker/bullet_collision_checker.h>
#include <bullet_collision_checker/types.h>

#include <iostream>
#include <sstream>
#include <vector>

namespace collision_checker {

struct BinaryCollisionCallback : public btCollisionWorld::ContactResultCallback {
  bool is_collision;

  BinaryCollisionCallback() : btCollisionWorld::ContactResultCallback(), is_collision(false) {}

  virtual btScalar addSingleResult(btManifoldPoint& cp,
    const btCollisionObjectWrapper* colObj0Wrap, int partId0, int index0,
    const btCollisionObjectWrapper* colObj1Wrap, int partId1, int index1) {
    is_collision = true;
    return 0;
  }
};

struct BinarySweptConvexCollisionCallback : public btCollisionWorld::ConvexResultCallback {
  bool is_collision;

  BinarySweptConvexCollisionCallback() : btCollisionWorld::ConvexResultCallback(), is_collision(false) {}

  virtual btScalar addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace) {
    is_collision = true;
    return 0;
  }
};

collision_checker::BulletCollisionChecker::BulletCollisionChecker() {
  /* Create essential bullet machinery.
  */

  m_coll_config = new btDefaultCollisionConfiguration();
  m_dispatcher = new btCollisionDispatcher(m_coll_config);

  double scene_size = 100;
  unsigned int max_objects = 100;
  btScalar sscene_size = (btScalar) scene_size;
  btVector3 worldAabbMin(-sscene_size, -sscene_size, -sscene_size);
  btVector3 worldAabbMax(sscene_size, sscene_size, sscene_size);

  m_broadphase = new bt32BitAxisSweep3(worldAabbMin, worldAabbMax, max_objects, 0, true);

  // m_broadphase = new btDbvtBroadphase();
  m_world = new btCollisionWorld(m_dispatcher, m_broadphase, m_coll_config);

  // set up the robot
  AddRobot(scp::Vec3{0.15, 0.15, 0.15}, scp::Vec3{0.0, 0.0, 0.0});
}

collision_checker::BulletCollisionChecker::~BulletCollisionChecker() {
  delete m_world;
  delete m_broadphase;
  delete m_dispatcher;
  delete m_coll_config;
  // delete cw;
  // delete broadphase;
  // delete dispatcher;
  // delete collisionConfiguration;
  // delete robot;

  for (uint i = 0; i < convex_robot_components.size(); i++) {
    delete convex_robot_components[i];
  }

  for (uint i = 0; i < convex_env_components.size(); i++) {
    delete convex_env_components[i];
  }
}


void BulletCollisionChecker::AddRobot(scp::Vec3 a, scp::Vec3 r, scp::Quat q) {
  /* Add an ellipsoidal robot. Default is 0.3m sphere at the origin (Astrobee).
  */
  robot = new btCollisionObject();
  SetTransformation(robot, r, q);
  // std::cout << "Creating ellipsoidal robot with semi-major axes (xyz): " << a[0] << " " << a[1] << " " << a[2] << std::endl;
  // btSphereShape* sphere_shape = new btSphereShape(a[0]);  // defaults to value in header
  // robot->setCollisionShape(sphere_shape);

  btVector3 pos(0.0, 0.0, 0.0);
  btScalar rad(1.0);
  btMultiSphereShape* ellipsoid_shape = new btMultiSphereShape(&pos, &rad, 1);
  ellipsoid_shape->setLocalScaling(btVector3(a(0), a(1), a(2)));
  ellipsoid_shape->setMargin(btScalar{0.0});  // disable default margin of 0.04
  robot->setCollisionShape(ellipsoid_shape);

  m_world->addCollisionObject(robot);

  convex_robot_components.push_back(robot);
}


void BulletCollisionChecker::AddObstacle(scp::Vec3 a, scp::Vec3 r, scp::Quat q) {
  /* Add an obstacle to the collision world. For now, assumes ellipsoidal. Details on ellipsoid
  creation: https://pybullet.org/Bullet/phpBB3/viewtopic.php?t=808

  @param:
  r: position
  q: quat (scalar last)
  a: semi-major axis length
  @return:
  convex_env_components: updated
  */
  btCollisionObject* obstacle = new btCollisionObject();
  SetTransformation(obstacle, r, q);
  // std::cout << "Creating ellipsoidal obstacle with semi-major axes (xyz): " << a[0] << " " << a[1] << " " << a[2] << std::endl;
  // btSphereShape* sphere_shape = new btSphereShape(a[0]);  // 0.2
  // obstacle->setCollisionShape(sphere_shape);

  btVector3 pos(0.0, 0.0, 0.0);
  btScalar rad(1.0);
  btMultiSphereShape* ellipsoid_shape = new btMultiSphereShape(&pos, &rad, 1);
  ellipsoid_shape->setLocalScaling(btVector3(a(0), a(1), a(2)));
  ellipsoid_shape->setMargin(btScalar{0.0});  // disable default margin of 0.04
  obstacle->setCollisionShape(ellipsoid_shape);

  m_world->addCollisionObject(obstacle);

  convex_env_components.push_back(obstacle);
}


void BulletCollisionChecker::SetTransformation(btCollisionObject* o, scp::Vec3 v, scp::Quat q) {
  o->getWorldTransform().setOrigin(btVector3(v(0), v(1), v(2)));
  o->getWorldTransform().setRotation(btQuaternion(q.x(), q.y(), q.z(), q.w()));
}

void BulletCollisionChecker::SetTransformation(btCollisionObject* o, scp::Vec3 v) {
  o->getWorldTransform().setOrigin(btVector3(v(0), v(1), v(2)));
}

std::vector<btCollisionObject*> BulletCollisionChecker::GetConvexComponents(btCollisionShape* cs) {
  btTransform tr;
  tr.setIdentity();
  return GetConvexComponents(cs, tr);
}

std::vector<btCollisionObject*> BulletCollisionChecker::GetConvexComponents(btCollisionObject* co) {
  return GetConvexComponents(co->getCollisionShape(), co->getWorldTransform());
}

std::vector<btCollisionObject*> BulletCollisionChecker::GetConvexComponents(btCollisionShape* cs, btTransform tr) {
  std::vector<btCollisionObject*> convex_components;

  if (cs->isConvex()) {
    btCollisionObject* cc = new btCollisionObject();
    cc->setCollisionShape(cs);
    cc->setWorldTransform(tr);
    convex_components.push_back(cc);
  } else if (cs->isCompound()) {
    btCompoundShape* cm = reinterpret_cast<btCompoundShape*>(cs);
    int num_children = cm->getNumChildShapes();
    for (int i = 0; i < num_children; i++) {
      // btTransform comp = tr * cm->getChildTransform(i);
      // TODO(acauligi): convex_components.push_back(GetConvexComponents(cm->getChildShape(i), comp));
    }
  }
  return convex_components;
}

bool BulletCollisionChecker::IsFreeState(scp::Vec3 v, scp::Quat q) {
  /* Check if the robot geometry is collision-free.
  @param:
  v: position
  q: quat (scalar last?)

  @return:
  !result.is_collision: true if state is free
  */
//  std::cout << "Checking: " << v << std::endl;
  SetTransformation(robot, v, q);
  m_world->performDiscreteCollisionDetection();
  BinaryCollisionCallback result;
  m_world->contactTest(robot, result);

  // std::cout << robot->getWorldTransform().getOrigin()[0] << std::endl;
  return !result.is_collision;
}

bool BulletCollisionChecker::IsFreeMotion(scp::Vec3 v, scp::Vec3 w) {
  bool free_motion = true;
  btCompoundShape* robot_compound = reinterpret_cast<btCompoundShape*>(robot->getCollisionShape());
  btTransform tr1, tr2;
  tr1.setIdentity();
  tr2.setIdentity();
  tr1.setOrigin(btVector3(v(0), v(1), v(2)));
  tr2.setOrigin(btVector3(w(0), w(1), w(2)));
  for (int i = 0; i < robot_compound->getNumChildShapes(); i++) {
    BinarySweptConvexCollisionCallback result;
    btConvexShape* robot_piece = reinterpret_cast<btConvexShape*>(robot_compound->getChildShape(i));
    m_world->convexSweepTest(robot_piece, tr1 * robot_compound->getChildTransform(i),
      tr2 * robot_compound->getChildTransform(i), result);
    if (result.is_collision) {
      free_motion = false;
      break;
    }
  }
  return free_motion;
}

bool BulletCollisionChecker::IsFreeMotion(scp::Vec3 v, scp::Quat vrot, scp::Vec3 w, scp::Quat wrot) {
  bool free_motion = true;
  btCompoundShape* robot_compound = reinterpret_cast<btCompoundShape*>(robot->getCollisionShape());

  btTransform tr1, tr2;
  tr1.setIdentity();
  tr2.setIdentity();
  tr1.setOrigin(btVector3(v(0), v(1), v(2)));
  tr2.setOrigin(btVector3(w(0), w(1), w(2)));
  tr1.setRotation(btQuaternion(vrot.x(), vrot.y(), vrot.z(), vrot.w()));
  tr2.setRotation(btQuaternion(wrot.x(), wrot.y(), wrot.z(), wrot.w()));

  for (int i = 0; i < robot_compound->getNumChildShapes(); i++) {
    BinarySweptConvexCollisionCallback result;
    btConvexShape* robot_piece = reinterpret_cast<btConvexShape*>(robot_compound->getChildShape(i));
    m_world->convexSweepTest(robot_piece, tr1 * robot_compound->getChildTransform(i),
      tr2 * robot_compound->getChildTransform(i), result);
    if (result.is_collision) {
      free_motion = false;
      break;
    }
  }
  return free_motion;
}

void BulletCollisionChecker::SetMargin(btCollisionObject* obj, scp::decimal_t dx = 0.0) {
  SetMargin(obj->getCollisionShape(), dx);
}

void BulletCollisionChecker::SetMargin(btCollisionShape* cs, scp::decimal_t dx = 0.0) {
  if (cs->isConvex()) {
    cs->setMargin(dx);
  } else if (cs->isCompound()) {
    btCompoundShape* cm = reinterpret_cast<btCompoundShape*>(cs);
    int num_children = cm->getNumChildShapes();
    for (int i = 0; i < num_children; i++) {
      SetMargin(cm->getChildShape(i), dx);
    }
  }
}

void BulletCollisionChecker::SetContactDistance(float dist) {
  m_contactDistance = dist;
  // SHAPE_EXPANSION = btVector3(1,1,1)*dist;
  // gContactBreakingThreshold = 2.001*dist; // wtf. when I set it to 2.0 there are no contacts with distance > 0
  btCollisionObjectArray& objs = m_world->getCollisionObjectArray();
  for (int i = 0; i < objs.size(); ++i) {
    objs[i]->setContactProcessingThreshold(dist);
  }
  btCollisionDispatcher* dispatcher = static_cast<btCollisionDispatcher*>(m_world->getDispatcher());
  dispatcher->setDispatcherFlags(dispatcher->getDispatcherFlags() &
    ~btCollisionDispatcher::CD_USE_RELATIVE_CONTACT_BREAKING_THRESHOLD);
}

void BulletCollisionChecker::ComputeDistance(size_t env_idx, SignedDistanceResult& out) {
  btScalar* result = new btScalar[7];
  result[0] = btScalar(BT_LARGE_FLOAT);

  btCollisionObject* co = convex_env_components[env_idx];
  btScalar max_d2 = btScalar(BT_LARGE_FLOAT);

  // signed distance, point on co1, point on co2;
  ComputeDistance(robot->getCollisionShape(), robot->getWorldTransform(),
                  co->getCollisionShape(), co->getWorldTransform(),
                  result, max_d2);

  out.sd = result[0];
  out.co1_pt(0) = result[1];
  out.co1_pt(1) = result[2];
  out.co1_pt(2) = result[3];
  out.co2_pt(0) = result[4];
  out.co2_pt(1) = result[5];
  out.co2_pt(2) = result[6];
}

void BulletCollisionChecker::ComputeDistance(const btCollisionShape* cs1, const btTransform& tr1,
                      const btCollisionShape* cs2, const btTransform& tr2,
                      btScalar* result, btScalar max_d2) {
  if (cs1->isConvex() && cs2->isConvex()) {
    btVoronoiSimplexSolver sGjkSimplexSolver;
    btGjkEpaPenetrationDepthSolver epa;
    sGjkSimplexSolver.setEqualVertexThreshold(0.f);
    btGjkPairDetector convexConvex(reinterpret_cast<const btConvexShape*>(cs1),
                                   reinterpret_cast<const btConvexShape*>(cs2),
                                   &sGjkSimplexSolver, &epa);
    btGjkPairDetector::ClosestPointInput input;
    btPointCollector output;
    input.m_transformA = tr1;
    input.m_transformB = tr2;
    input.m_maximumDistanceSquared = max_d2;

    convexConvex.getClosestPoints(input, output, 0);
    if (output.m_hasResult) {
      if (output.m_distance < result[0]) {
        result[0] = output.m_distance;
        result[1] = output.m_pointInWorld.x() + output.m_distance*output.m_normalOnBInWorld.x();
        result[2] = output.m_pointInWorld.y() + output.m_distance*output.m_normalOnBInWorld.y();
        result[3] = output.m_pointInWorld.z() + output.m_distance*output.m_normalOnBInWorld.z();
        result[4] = output.m_pointInWorld.x();
        result[5] = output.m_pointInWorld.y();
        result[6] = output.m_pointInWorld.z();
      }
    }
  } else if (cs1->isCompound()) {
    const btCompoundShape* com1 = reinterpret_cast<const btCompoundShape*>(cs1);
    for (int i = 0; i < com1->getNumChildShapes(); i++) {
      ComputeDistance(com1->getChildShape(i), tr1 * com1->getChildTransform(i), cs2, tr2, result, max_d2);
    }
  } else if (cs2->isCompound()) {
    const btCompoundShape* com2 = reinterpret_cast<const btCompoundShape*>(cs2);
    for (int i = 0; i < com2->getNumChildShapes(); i++) {
      ComputeDistance(cs1, tr1, com2->getChildShape(i), tr2 * com2->getChildTransform(i), result, max_d2);
    }
  } else {
    result[0] = -1;
  }
}

/*
std::vector<Eigen::Vector3f> load_map() {
  std::vector<ff_msgs::Zone> zones;
  bool got = GetZones(zones);
  if (!got) return false;

  uint num_keepin = 0;
  Eigen::Vector3f min, max;
  min << 1000.0, 1000.0, 1000.0;
  max << -1000.0, -1000.0, -1000.0;
  uint num_keepin = 0;
  std::vector<BulletCollisionObjectPtr> keep_in_zones_;

  for (auto &zone : zones) {
    if (zone.type == ff_msgs::Zone::KEEPIN) {
      Eigen::Vector3f zmin, zmax, halfextents, midpoint;
      zmin << zone.min.x, zone.min.y, zone.min.z;
      zmax << zone.max.x, zone.max.y, zone.max.z;
      halfextents = (zmax-zmin)/2;
      midpoint = (zmin+zmax)/2;

      btCollisionObject* box = new btCollisionObject();
      btBoxShape* box_shape = new btBoxShape(btVector3(halfextents(0),halfextents(1),halfextents(2)));
      box_shape->setMargin(0.);
      box->getWorldTransform().setOrigin(btVector3(mid(0),mid(1),mid(2)));
      box->setCollisionShape(box_shape);
      keep_in_zones_.push_back(box);

      for (int i = 0; i < 3; i++) {
        min(i) = std::min(min(i), zmin(i));
        min(i) = std::min(min(i), zmax(i));
        max(i) = std::max(max(i), zmin(i));
        max(i) = std::max(max(i), zmax(i));
      }
      num_keepin++;
    }
  }
  if (num_keepin == 0) {
    ROS_ERROR("Zero keepin zones!! Plan failed");
    return false;
  }

  double map_res_{0.5};     // map resolution
  min -= Eigen::Vector3f::Ones() * map_res_ * 2.0;
  max += Eigen::Vector3f::Ones() * map_res_ * 2.0;

  return std::vector<Eigen::Vector3f>(min,max);
}

std::vector<btTransform> rightMultiplyAll(const std::vector<btTransform>& xs, const btTransform& y) {
  vector<btTransform> out(xs.size());
  for (int i=0; i < xs.size(); ++i) out[i] = xs[i]*y;
  return out;
}

void ContinuousCheckShape(btCollisionShape* shape, const vector<btTransform>& transforms,
    KinBody::Link* link, btCollisionWorld* world, vector<Collision>& collisions) {
  if (btConvexShape* convex = dynamic_cast<btConvexShape*>(shape)) {
    for (int i=0; i < transforms.size()-1; ++i) {
      btCollisionWorld::ClosestConvexResultCallback ccc(btVector3(NAN, NAN, NAN), btVector3(NAN, NAN, NAN));
      ccc.m_collisionFilterMask = KinBodyFilter;
      world->convexSweepTest(convex, transforms[i], transforms[i+1], ccc, 0);
      if (ccc.hasHit()) {
        collisions.push_back(Collision(link, getLink(ccc.m_hitCollisionObject),
            toOR(ccc.m_hitPointWorld), toOR(ccc.m_hitPointWorld),
            toOR(ccc.m_hitNormalWorld), 0, 1, i+ccc.m_closestHitFraction));
      }
    }
  }
  else if (btCompoundShape* compound = dynamic_cast<btCompoundShape*>(shape)) {
    for (int i = 0; i < compound->getNumChildShapes(); ++i) {
      ContinuousCheckShape(compound->getChildShape(i),
        rightMultiplyAll(transforms, compound->getChildTransform(i)),  link, world, collisions);
    }
  }
  else {
    string error = "Can only continuous collision check cvx shapes and compound shapes made of cvx shapes";
    throw std::runtime_error(error);
  }
}
*/
}  // namespace collision_checker