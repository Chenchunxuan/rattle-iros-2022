// Generated by gencpp from file reswarm_msgs/ReswarmSrvMRPI.msg
// DO NOT EDIT!


#ifndef RESWARM_MSGS_MESSAGE_RESWARMSRVMRPI_H
#define RESWARM_MSGS_MESSAGE_RESWARMSRVMRPI_H

#include <ros/service_traits.h>


#include <reswarm_msgs/ReswarmSrvMRPIRequest.h>
#include <reswarm_msgs/ReswarmSrvMRPIResponse.h>


namespace reswarm_msgs
{

struct ReswarmSrvMRPI
{

typedef ReswarmSrvMRPIRequest Request;
typedef ReswarmSrvMRPIResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReswarmSrvMRPI
} // namespace reswarm_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::reswarm_msgs::ReswarmSrvMRPI > {
  static const char* value()
  {
    return "18c526b9caac12dfc97661beaa4f186e";
  }

  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPI&) { return value(); }
};

template<>
struct DataType< ::reswarm_msgs::ReswarmSrvMRPI > {
  static const char* value()
  {
    return "reswarm_msgs/ReswarmSrvMRPI";
  }

  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPI&) { return value(); }
};


// service_traits::MD5Sum< ::reswarm_msgs::ReswarmSrvMRPIRequest> should match 
// service_traits::MD5Sum< ::reswarm_msgs::ReswarmSrvMRPI > 
template<>
struct MD5Sum< ::reswarm_msgs::ReswarmSrvMRPIRequest>
{
  static const char* value()
  {
    return MD5Sum< ::reswarm_msgs::ReswarmSrvMRPI >::value();
  }
  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPIRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::reswarm_msgs::ReswarmSrvMRPIRequest> should match 
// service_traits::DataType< ::reswarm_msgs::ReswarmSrvMRPI > 
template<>
struct DataType< ::reswarm_msgs::ReswarmSrvMRPIRequest>
{
  static const char* value()
  {
    return DataType< ::reswarm_msgs::ReswarmSrvMRPI >::value();
  }
  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPIRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::reswarm_msgs::ReswarmSrvMRPIResponse> should match 
// service_traits::MD5Sum< ::reswarm_msgs::ReswarmSrvMRPI > 
template<>
struct MD5Sum< ::reswarm_msgs::ReswarmSrvMRPIResponse>
{
  static const char* value()
  {
    return MD5Sum< ::reswarm_msgs::ReswarmSrvMRPI >::value();
  }
  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPIResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::reswarm_msgs::ReswarmSrvMRPIResponse> should match 
// service_traits::DataType< ::reswarm_msgs::ReswarmSrvMRPI > 
template<>
struct DataType< ::reswarm_msgs::ReswarmSrvMRPIResponse>
{
  static const char* value()
  {
    return DataType< ::reswarm_msgs::ReswarmSrvMRPI >::value();
  }
  static const char* value(const ::reswarm_msgs::ReswarmSrvMRPIResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // RESWARM_MSGS_MESSAGE_RESWARMSRVMRPI_H