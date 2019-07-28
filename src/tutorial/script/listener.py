#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

class Listener:
    def __init__(self):
        self.sub = rospy.Subscriber("/chatter", String, self.callback)

    def callback(sef, data):
        rospy.loginfo(" I heard %s", data.data)

if __name__ == '__main__':
    rospy.init_node('listener', anonymous = True)
    Listener()
    rospy.spin()

'''
def callback(data):
    rospy.loginfo(rospy.get_caller_id() + " I heard %s", data.data)

def listener():
    rospy.init_node('listener', anonymous = True)
    rospy.Subscriber("chatter", String, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
'''
