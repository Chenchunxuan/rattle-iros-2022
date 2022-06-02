// Generated by gencpp from file reswarm_msgs/ReswarmCasadiStatus.msg
// DO NOT EDIT!


#ifndef RESWARM_MSGS_MESSAGE_RESWARMCASADISTATUS_H
#define RESWARM_MSGS_MESSAGE_RESWARMCASADISTATUS_H


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
struct ReswarmCasadiStatus_
{
  typedef ReswarmCasadiStatus_<ContainerAllocator> Type;

  ReswarmCasadiStatus_()
    : stamp()
    , coord_ok(false)
    , mrpi_finished(false)
    , traj_finished(false)
    , control_mode()  {
    }
  ReswarmCasadiStatus_(const ContainerAllocator& _alloc)
    : stamp()
    , coord_ok(false)
    , mrpi_finished(false)
    , traj_finished(false)
    , control_mode(_alloc)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef uint8_t _coord_ok_type;
  _coord_ok_type coord_ok;

   typedef uint8_t _mrpi_finished_type;
  _mrpi_finished_type mrpi_finished;

   typedef uint8_t _traj_finished_type;
  _traj_finished_type traj_finished;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _control_mode_type;
  _control_mode_type control_mode;





  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> const> ConstPtr;

}; // struct ReswarmCasadiStatus_

typedef ::reswarm_msgs::ReswarmCasadiStatus_<std::allocator<void> > ReswarmCasadiStatus;

typedef boost::shared_ptr< ::reswarm_msgs::ReswarmCasadiStatus > ReswarmCasadiStatusPtr;
typedef boost::shared_ptr< ::reswarm_msgs::ReswarmCasadiStatus const> ReswarmCasadiStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c10c75bfe58d45337011894405a5c1a0";
  }

  static const char* value(const ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc10c75bfe58d4533ULL;
  static const uint64_t static_value2 = 0x7011894405a5c1a0ULL;
};

template<class ContainerAllocator>
struct DataType< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "reswarm_msgs/ReswarmCasadiStatus";
  }

  static const char* value(const ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n"
"bool coord_ok\n"
"bool mrpi_finished\n"
"bool traj_finished\n"
"string control_mode\n"
"\n"
;
  }

  static const char* value(const ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.coord_ok);
      stream.next(m.mrpi_finished);
      stream.next(m.traj_finished);
      stream.next(m.control_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReswarmCasadiStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::reswarm_msgs::ReswarmCasadiStatus_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "coord_ok: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.coord_ok);
    s << indent << "mrpi_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mrpi_finished);
    s << indent << "traj_finished: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.traj_finished);
    s << indent << "control_mode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.control_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RESWARM_MSGS_MESSAGE_RESWARMCASADISTATUS_H