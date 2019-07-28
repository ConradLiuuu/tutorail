#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

class Talker:
    def __init__(self):
        self.rate = rospy.Rate(5) ## publish 5 times per secend
        self.pub = rospy.Publisher('/chatter', String, queue_size = 10)
        self.time = 0
    def talk(self):
        self.time = rospy.get_rostime()
        talk_str = "hello word %s" % self.time.secs
        rospy.loginfo(talk_str)
        self.pub.publish(talk_str)
        self.rate.sleep()
        
if __name__ == '__main__':
    rospy.init_node('talker', anonymous = True)
    talker = Talker()
    while not rospy.is_shutdown():
        talker.talk()
'''
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
'''
