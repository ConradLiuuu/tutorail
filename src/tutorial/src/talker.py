#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String
import time
def talker():
    pub = rospy.Publisher('chatter', String, queue_size = 10)
    rospy.init_node('talker', anonymous = True)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        talk_str = "hello word %s" % time.time()
        rospy.loginfo(talk_str)
        pub.publish(talk_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptRxception:
        pass
