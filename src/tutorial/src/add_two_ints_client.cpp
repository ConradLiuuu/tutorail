#include <ros/ros.h>
#include <tutorial/AddTwoInts.h>
#include <cstdlib>
using namespace ros;

class Add_two_ints_client
{
private:
  NodeHandle nh;
  ServiceClient client;

public:
  Add_two_ints_client()
  {
    client = nh.serviceClient<tutorial::AddTwoInts>("add_two_ints");
  }
};

int main(int argc, char **argv)
{
  init(argc, argv, "add_two_ints_client");

  if (argc != 3){
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  NodeHandle nh;
  ServiceClient client = nh.serviceClient<tutorial::AddTwoInts>("add_two_ints");

  tutorial::AddTwoInts srv;
  srv.request.a = atoi(argv[1]);
  srv.request.b = atoi(argv[2]);

  if (client.call(srv)){
    ROS_INFO("sum:%d", srv.response.sum);
  }
  
  return 0;
}
