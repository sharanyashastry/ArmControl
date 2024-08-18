#include "KinematicChain.h"
#include <cmath>

void KinematicChain::set_joint_positions(std::vector<double> q_vector){
    for(int i = 0; i < joints_.size(); i++){
        joints_[i].set_position(q_vector[i]);
    }
}

Eigen::Vector3d KinematicChain::PositionFK(){
    Eigen::Vector3d ee_position(0, 0, 0);
    double theta = 0;

    for(int i = 0; i < joints_.size(); i++){
        if(joints_[i].get_type() == Joint::Type::PRISMATIC){
            ee_position[0] += links_[i].get_position()*cos(theta);
            ee_position[1] += links_[i].get_position()*sin(theta);
        }
        else if(joints_[i].get_type() == Joint::Type::REVOLUTE){
            theta += joints_[i].get_position();
            ee_position[0] += links_[i].get_position()*cos(theta);
            ee_position[1] += links_[i].get_position()*sin(theta);
        }
    }   
    return ee_position;
}