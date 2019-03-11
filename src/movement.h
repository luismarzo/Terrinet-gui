#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <fstream>
#include <iostream>
#include <ros/ros.h>
#include <uav_abstraction_layer/GoToWaypoint.h>
#include <uav_abstraction_layer/TakeOff.h>
#include <uav_abstraction_layer/Land.h>
#include <uav_abstraction_layer/SetVelocity.h>
#include <QDialog>
#include "geometry_msgs/Twist.h"
#include "ackermann_msgs/AckermannDriveStamped.h"
#include "ackermann_msgs/AckermannDrive.h"

namespace Ui {
class Movement;
}

class Movement : public QDialog
{
    Q_OBJECT

public:
    explicit Movement(QWidget *parent = 0);
    ~Movement();

private slots:


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_sendtopic_clicked();

    void on_sendpose_clicked();

    void on_takeoff_clicked();

    void on_land_clicked();


private:

    Ui::Movement *ui;
    ros::NodeHandle _n,_m;
    ros::Publisher _pi_pub;
    ros::Publisher _bob_pub;
    ros::Publisher _agv_pub;

    ros::ServiceClient _takeoff_cli;
    ros::ServiceClient _waypoint_cli;
    ros::ServiceClient _land_cli;
    ros::ServiceClient _vel_cli;

    uav_abstraction_layer::TakeOff _takeoff_msg;
    uav_abstraction_layer::GoToWaypoint _waypoint_msg;
    uav_abstraction_layer::Land _land_msg;

    geometry_msgs::Twist _piomsg;
    ackermann_msgs::AckermannDriveStamped _bobmsg;
    ackermann_msgs::AckermannDrive _agvmsg;
    bool _pio=false,_bob=false,_agv=false;
    QString _carvel,_steer,_posx,_posy,_posz,_orix,_oriy,_oriz,_uavel,_id;




};

#endif // MOVEMENT_H
