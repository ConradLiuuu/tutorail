#include <ros/ros.h>
#include <tutorial/AddTwoInts.h>
using namespace ros;

class Add_two_ints_server
{
private:
  NodeHandle nh;
  ServiceServer server;

public:
  Add_two_ints_server()
  {
    server = nh.advertiseService("add_two_ints", &Add_two_ints_server::add_callback, this);
  }

  bool add_callback(tutorial::AddTwoInts::Request &req, tutorial::AddTwoInts::Response &res)
  {
    res.sum = req.a + req.b;
    ROS_INFO("Request %d + %d", req.a, req.b);
    ROS_INFO("Response sum = %d", res.sum);
    ROS_INFO("------------------");
    return true;
  }
};

int main(int argc, char **argv)
{
  init(argc, argv, "add_two_ints_server");
  Add_two_ints_server server;
  ROS_INFO("Add two ints server is opened");
  spin();
}
