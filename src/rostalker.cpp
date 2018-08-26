#include "rostalker.h"

void RosTalker::talk(){
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"hello world";
    msg.data = ss.str();
    msg_pub.publish(msg);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "rosTalker");
    RosTalker rt;
    ros::Rate loop_rate(5);
    while(ros::ok()){
        rt.talk();
        loop_rate.sleep();
    }
    return 0;
}

