// Generated by gencpp from file reswarm_msgs/ReswarmStatusPrimary.msg
// DO NOT EDIT!


#ifndef RESWARM_MSGS_MESSAGE_RESWARMSTATUSPRIMARY_H
#define RESWARM_MSGS_MESSAGE_RESWARMSTATUSPRIMARY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace reswarm_msgs
{
template <class ContainerAllocator>
struct ReswarmStatusPrimary_
{
  typedef ReswarmStatusPrimary_<ContainerAllocator> Type;

  ReswarmStatusPrimary_()
    : stamp()
    , test_number(0)
    , default_control(false)
    , flight_mode()
    , test_finished(false)
    , coord_ok(false)
    , control_mode()
    , regulate_finished(false)
    , uc_bound_activated(false)
    , uc_bound_finished(false)
    , mrpi_finished(false)
    , traj_sent(false)
    , traj_finished(false)
    , gain_mode(0)
    , lqrrrt_activated(false)
    , lqrrrt_finished(false)
    , info_traj_send(false)
    , solver_status(0)
    , cost_value(0.0)
    , kkt_value(0.0)
    , sol_time(0.0)  {
    }
  ReswarmStatusPrimary_(const ContainerAllocator& _alloc)
    : stamp()
    , test_number(0)
    , default_control(false)
    , flight_mode(_alloc)
    , test_finished(false)
    , coord_ok(false)
    , control_mode(_alloc)
    , regulate_finished(false)
    , uc_bound_activated(false)
    , uc_bound_finished(false)
    , mrpi_finished(false)
    , traj_sent(false)
    , traj_finished(false)
    , gain_mode(0)
    , lqrrrt_activated(false)
    , lqrrrt_finished(false)
    , info_traj_send(false)
    , solver_status(0)
    , cost_value(0.0)
    , kkt_value(0.0)
    , sol_time(0.0)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef int32_t _test_number_type;
  _test_number_type test_number;

   typedef uint8_t _default_control_type;
  _default_control_type default_control;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _flight_mode_type;
  _flight_mode_type flight_mode;

   typedef uint8_t _test_finished_type;
  _test_finished_type test_finished;

   typedef uint8_t _coord_ok_type;
  _coord_ok_type coord_ok;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _control_mode_type;
  _control_mode_type control_mode;

   typedef uint8_t _regulate_finished_type;
  _regulate_finished_type regulate_finished;

   typedef uint8_t _uc_bound_activated_type;
  _uc_bound_activated_type uc_bound_activated;

   typedef uint8_t _uc_bound_finished_type;
  _uc_bound_finished_type uc_bound_finished;

   typedef uint8_t _mrpi_finished_type;
  _mrpi_finished_type mrpi_finished;

   typedef uint8_t _traj_sent_type;
  _traj_sent_type traj_sent;

   typedef uint8_t _traj_finished_type;
  _traj_finished_type traj_finished;

   typedef int32_t _gain_mode_type;
  _gain_mode_type gain_mode;

   typedef uint8_t _lqrrrt_activated_type;
  _lqrrrt_activated_type lqrrrt_activated;

   typedef uint8_t _lqrrrt_finished_type;
  _lqrrrt_finished_type lqrrrt_finished;

   typedef uint8_t _info_traj_send_type;
  _info_traj_send_type info_traj_send;

   typedef int32_t _solver_status_type;
  _solver_status_type solver_status;

   typedef float _cost_value_type;
  _cost_value_type cost_value;

   typedef float _kkt_value_type;
  _kkt_value_type kkt_value;

   typedef float _sol_time_type;
  _sol_time_type sol_time;





  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> const> ConstPtr;

}; // struct ReswarmStatusPrimary_

typedef ::reswarm_msgs::ReswarmStatusPrimary_<std::allocator<void> > ReswarmStatusPrimary;

typedef boost::shared_ptr< ::reswarm_msgs::ReswarmStatusPrimary > ReswarmStatusPrimaryPtr;
typedef boost::shared_ptr< ::reswarm_msgs::ReswarmStatusPrimary const> ReswarmStatusPrimaryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace reswarm_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg'], 'reswarm_msgs': ['/home/albee/workspaces/astrobee-ws-reswarm/freeflyer-reswarm/develop/reswarm_msgs/reswarm_msgs_matlab/matlab_msg_gen_ros1/glnxa64/src/reswarm_msgs/msg'], 'std_msgs': ['/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9276f61c14b13d5399601a4a9f59f5d6";
  }

  static const char* value(const ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9276f61c14b13d53ULL;
  static const uint64_t static_value2 = 0x99601a4a9f59f5d6ULL;
};

template<class ContainerAllocator>
struct DataType< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
{
  static const char* value()
  {
    return "reswarm_msgs/ReswarmStatusPrimary";
  }

  static const char* value(const ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n"
"\n"
"# base (shared) values\n"
"int32 test_number\n"
"bool default_control\n"
"string flight_mode\n"
"bool test_finished\n"
"bool coord_ok\n"
"\n"
"# PrimaryStatus\n"
"string control_mode  # did something break?\n"
"\n"
"# Test Progress\n"
"## regulation\n"
"bool regulate_finished\n"
"\n"
"## uc_bound for tube MPC\n"
"bool uc_bound_activated\n"
"bool uc_bound_finished\n"
"\n"
"## mrpi for tube MPC\n"
"bool mrpi_finished\n"
"\n"
"## tube MPC\n"
"bool traj_sent\n"
"bool traj_finished\n"
"int32 gain_mode\n"
"\n"
"## lqrrrt\n"
"bool lqrrrt_activated\n"
"bool lqrrrt_finished\n"
"\n"
"## info rich traj\n"
"bool info_traj_send  # used by info_rich_traj to start sending setpoints \n"
"\n"
"## DMPC\n"
"int32 solver_status\n"
"float32 cost_value\n"
"float32 kkt_value\n"
"float32 sol_time\n"
;
  }

  static const char* value(const ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.test_number);
      stream.next(m.default_control);
      stream.next(m.flight_mode);
      stream.next(m.test_finished);
      stream.next(m.coord_ok);
      stream.next(m.control_mode);
      stream.next(m.regulate_finished);
      stream.next(m.uc_bound_activated);
      stream.next(m.uc_bound_finished);
      stream.next(m.mrpi_finished);
      stream.next(m.traj_sent);
      stream.next(m.traj_finished);
      stream.next(m.gain_mode);
      stream.next(m.lqrrrt_activated);
      stream.next(m.lqrrrt_finished);
      stream.next(m.info_traj_send);
      stream.next(m.solver_status);
      stream.next(m.cost_value);
      stream.next(m.kkt_value);
      stream.next(m.sol_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReswarmStatusPrimary_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::reswarm_msgs::ReswarmStatusPrimary_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "test_number: ";
    Printer<int32_t>::stream(s, indent + "  ", v.test_number);
    s << indent << "default_control: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.default_control);
    s << indent << "flight_mode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.flight_mode);
    s << indent << "test_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.test_finished);
    s << indent << "coord_ok: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.coord_ok);
    s << indent << "control_mode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.control_mode);
    s << indent << "regulate_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.regulate_finished);
    s << indent << "uc_bound_activated: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.uc_bound_activated);
    s << indent << "uc_bound_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.uc_bound_finished);
    s << indent << "mrpi_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mrpi_finished);
    s << indent << "traj_sent: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.traj_sent);
    s << indent << "traj_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.traj_finished);
    s << indent << "gain_mode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gain_mode);
    s << indent << "lqrrrt_activated: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.lqrrrt_activated);
    s << indent << "lqrrrt_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.lqrrrt_finished);
    s << indent << "info_traj_send: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.info_traj_send);
    s << indent << "solver_status: ";
    Printer<int32_t>::stream(s, indent + "  ", v.solver_status);
    s << indent << "cost_value: ";
    Printer<float>::stream(s, indent + "  ", v.cost_value);
    s << indent << "kkt_value: ";
    Printer<float>::stream(s, indent + "  ", v.kkt_value);
    s << indent << "sol_time: ";
    Printer<float>::stream(s, indent + "  ", v.sol_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RESWARM_MSGS_MESSAGE_RESWARMSTATUSPRIMARY_H