#ifndef ROS_LISTENER_H
#define ROS_LISTENER_H
#include <ros/ros.h>
#include "std_msgs/String.h"

class RosListener{
public:
    RosListener(){
    msg_sub = nh.subscribe("talker_msg", 1000, &RosListener::msgCallback, this);
    }
    ros::NodeHandle nh;
    ros::Subscriber msg_sub;
    void msgCallback(const std_msgs::String & );
};
#endif

