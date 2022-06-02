// Generated by gencpp from file reswarm_msgs/ReswarmTestNumber.msg
// DO NOT EDIT!


#ifndef RESWARM_MSGS_MESSAGE_RESWARMTESTNUMBER_H
#define RESWARM_MSGS_MESSAGE_RESWARMTESTNUMBER_H


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
struct ReswarmTestNumber_
{
  typedef ReswarmTestNumber_<ContainerAllocator> Type;

  ReswarmTestNumber_()
    : stamp()
    , test_number(0)
    , role()  {
    }
  ReswarmTestNumber_(const ContainerAllocator& _alloc)
    : stamp()
    , test_number(0)
    , role(_alloc)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef int32_t _test_number_type;
  _test_number_type test_number;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _role_type;
  _role_type role;





  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> const> ConstPtr;

}; // struct ReswarmTestNumber_

typedef ::reswarm_msgs::ReswarmTestNumber_<std::allocator<void> > ReswarmTestNumber;

typedef boost::shared_ptr< ::reswarm_msgs::ReswarmTestNumber > ReswarmTestNumberPtr;
typedef boost::shared_ptr< ::reswarm_msgs::ReswarmTestNumber const> ReswarmTestNumberConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a546cf58ee360e93604091100205de8f";
  }

  static const char* value(const ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa546cf58ee360e93ULL;
  static const uint64_t static_value2 = 0x604091100205de8fULL;
};

template<class ContainerAllocator>
struct DataType< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
{
  static const char* value()
  {
    return "reswarm_msgs/ReswarmTestNumber";
  }

  static const char* value(const ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n"
"int32 test_number\n"
"string role\n"
;
  }

  static const char* value(const ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.test_number);
      stream.next(m.role);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReswarmTestNumber_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::reswarm_msgs::ReswarmTestNumber_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "test_number: ";
    Printer<int32_t>::stream(s, indent + "  ", v.test_number);
    s << indent << "role: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.role);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RESWARM_MSGS_MESSAGE_RESWARMTESTNUMBER_H