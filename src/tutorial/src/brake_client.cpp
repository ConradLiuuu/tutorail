#include <ros/ros.h>
#include <tutorial/license.h>

using namespace ros;

/*
class Brake_client
{
private:
  NodeHandle nh;
  ServiceClient client;

public:
  Brake_client()
  {
    client = nh.serviceClient<tutorial::license>("brake_identify");
  }

};
*/
int main(int argc, char** argv)
{
  init(argc, argv, "brake_client");

  if (argc != 2){
    ROS_INFO("please enter license plate");
    ROS_INFO("Usage:brake_client license plate");
  }

  NodeHandle nh;
  ServiceClient client = nh.serviceClient<tutorial::license>("brake_identify");

  tutorial::license brake_srv;
  brake_srv.request.licenscs_plate = argv[1];

  if (client.call(brake_srv)){
    ROS_INFO("Entered license plate is %s", brake_srv.request.licenscs_plate.c_str());
    ROS_INFO("Identify result is %s", brake_srv.response.brake_or_not.c_str());
  }
  
  return 0;
}
