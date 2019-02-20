#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <fstream>
#include <iostream>
#include <ros/ros.h>
#include <QDialog>
#include "geometry_msgs/Twist.h"
#include "ackermann_msgs/AckermannDriveStamped.h"

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


private:

    Ui::Movement *ui;
    ros::NodeHandle _n,_m;
    ros::Publisher _pi_pub;
    ros::Publisher _bob_pub;

    geometry_msgs::Twist _piomsg;
    ackermann_msgs::AckermannDriveStamped _bobmsg;
    bool _pio=false,_bob=false,_agv=false;
    QString _vel,_steer;




};

#endif // MOVEMENT_H
