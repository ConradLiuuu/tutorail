#include <ros/ros.h>
#include <tutorial/license.h>

using namespace ros;

class Brake_server
{
private:
  NodeHandle nh;
  ServiceServer server;

public:
  Brake_server()
  {
    server = nh.advertiseService("brake_identify", &Brake_server::callback, this);
  }
  bool callback(tutorial::license::Request &req, tutorial::license::Response &res)
  {
    if (req.licenscs_plate == "391-TFU"){
      res.brake_or_not = "true";
    }
    else if (req.licenscs_plate == "429-PRY"){
      res.brake_or_not = "true";
    }
    else if (req.licenscs_plate == "106-JUD"){
      res.brake_or_not = "true";
    }
    else{
      res.brake_or_not = "false";
    }
    ROS_INFO("Receive request ,license plate is %s", req.licenscs_plate.c_str());
    ROS_INFO("Identify result is %s", res.brake_or_not.c_str());
    ROS_INFO("------------------");
    return true;
  }

};

int main(int argc, char** argv)
{
  init(argc, argv, "brake_server");
  Brake_server brake_identify_server;
  ROS_INFO("Brake identify system is opened");
  ROS_INFO("------------------");
  spin();
}

