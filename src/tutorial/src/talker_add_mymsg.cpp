#include "ros/ros.h"
#include "tutorial/my_msg.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_add_mymsg");
  ros::NodeHandle nh;
  double freq;
  nh.getParam("/freq",freq);

  ros::Publisher chatter_pub = nh.advertise<tutorial::my_msg>("chatter", 1000);

  ros::Rate loop_rate(10);
  int cnt = 0;

  while (ros::ok())
  {
    tutorial::my_msg msg;
    msg.id = cnt;
    msg.title = "test";
    msg.content = "c++ customer msg test";

    chatter_pub.publish(msg);

    ros::spinOnce();

    //loop_rate.sleep();
    ros::Duration(freq).sleep();
    cnt ++;
  }

  return 0;
}
