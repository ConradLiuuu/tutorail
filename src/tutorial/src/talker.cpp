#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
using namespace ros;

class Talker
{
private:
  NodeHandle nh;
  Publisher chatter;
  Publisher counter;
  Timer timer_str;
  Timer timer_cnt;
  int cnt;

public:
  Talker()
  {
    cnt = 0;
    chatter = nh.advertise<std_msgs::String>("/chatter", 10);
    counter = nh.advertise<std_msgs::UInt8>("/counter", 10);
    timer_str = nh.createTimer(ros::Duration(1.0 / 5.0),std::bind(&Talker::pub_string, this));
    timer_cnt = nh.createTimer(ros::Duration(1.0 / 10.0),std::bind(&Talker::pub_counter, this));
  }
  void pub_string()
  {
    std_msgs::String str_msg;
    str_msg.data = "hello world";
    ROS_INFO("%s", str_msg.data.c_str());
    chatter.publish(str_msg);
  }

  void pub_counter()
  {
    std_msgs::UInt8 uint8_msg;
    uint8_msg.data = cnt;
    counter.publish(uint8_msg);
    cnt ++;
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  Talker talker;
  spin();
  return 0;
}

/*
int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher chatter = nh.advertise<std_msgs::String>("chatter", 10);
    ros::Rate rate(10);

    int cnt = 0;

    while (ros::ok()){
        std_msgs:: String str_msg;
        str_msg.data = "hello world";

        ROS_INFO("%s",str_msg.data.c_str());
        chatter.publish(str_msg);
        ros::spinOnce();
        rate.sleep();
        cnt ++;
    }
    return 0;
}
*/
