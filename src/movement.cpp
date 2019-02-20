#include "movement.h"
#include "ui_movement.h"
#include <QTextStream>
#include <QProcess>
#include <QStringList>
#include <QColor>
#include <QColorDialog>

#include <iostream>
#include <ros/ros.h>
#include <fstream>




Movement::Movement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Movement)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Pioneer");
    ui->comboBox->addItem("Bobcat");
    ui->comboBox->addItem("Agv");


}

Movement::~Movement()
{
    delete ui;

}



void Movement::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->comboBox->currentText() == "Pioneer"){

        _pi_pub = _n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
        _pio=true;
        _bob=false;
        _agv=false;
    }
    else if(ui->comboBox->currentText() == "Bobcat"){

        _bob_pub = _m.advertise<ackermann_msgs::AckermannDriveStamped>("/zzz", 1000);
        _pio=false;
        _bob=true;
        _agv=false;
    }
    else if(ui->comboBox->currentText() == "Agv"){

        _pio=false;
        _bob=false;
        _agv=true;
    }
}


void Movement::on_sendtopic_clicked(){

    float vel,steer;

    _vel=ui->lineEdit_vel->text();
    _steer=ui->lineEdit_ste->text();
    vel=_vel.toFloat();
    steer=_steer.toFloat();


    if(_pio=='1'){
        _piomsg.linear.x=vel;
        _piomsg.angular.z=steer;
        _pi_pub.publish(_piomsg);


    }
    else if(_bob=='1'){
        std::cout<<"bobi";
        _bobmsg.drive.speed=vel;
        _bobmsg.drive.steering_angle=steer;
        _bob_pub.publish(_bobmsg);

    }
    else if(_agv=='1'){

    }

}






