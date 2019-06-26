#include "ros/ros.h"
#include "std_msgs/String.h"

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
