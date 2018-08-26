#ifndef ROS_TALKER_H
#define ROS_TALKER_H

#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>

class RosTalker{
public:
    RosTalker(){
        msg_pub = nh.advertise<std_msgs::String>("talker_msg", 1000);
    }
    ros::NodeHandle nh;
    ros::Publisher msg_pub;
    void talk();
    int add(int a, int b){
        return a + b;
    }
};
#endif

