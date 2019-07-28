#include <ros/ros.h>
#include <std_msgs/String.h>
using namespace ros;

class Listener
{
private:
  NodeHandle nh;
  Subscriber sub;

public:
  Listener()
  {
    sub = nh.subscribe("/chatter", 10, &Listener::callback, this);
  }

  void callback(const std_msgs::String::ConstPtr& str_msg)
  {
    ROS_INFO("heard %s",str_msg->data.c_str());
  }
};

int main(int argc, char **argv)
{
  init(argc, argv ,"listener");
  Listener listener;
  spin();
  return 0;
}

/*
void callback(const std_msgs::String::ConstPtr& str_msg){
    ROS_INFO("heard %s",str_msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("chatter",10,callback);
  ros::spin();
  return 0;
}*/
