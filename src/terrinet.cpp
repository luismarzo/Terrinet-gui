#include "terrinet.h"
#include "ui_terrinet.h"
#include <QTextStream>
#include <QProcess>
#include <QStringList>
#include <QColor>
#include <QColorDialog>

#include <iostream>
#include <ros/ros.h>
#include <fstream>




Terrinet::Terrinet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Terrinet)
{
    ui->setupUi(this);
    //ui->pushButton_10->setVisible(0);
    ui->comboBox->addItem("Px4 bringup");
    ui->comboBox->addItem("Uav abstraction layer");
    //quita esto cuando vayas a usar los algoritmos con la interfaz
    //ui->label_3->setVisible(0);
    //ui->label_4->setVisible(0);
    //ui->label_5->setVisible(0);
    ui->commandLinkButton->setVisible(0);
    ui->lineEdit_2->setVisible(0);
    ui->lineEdit->setVisible(0);
    ui->lineEdit_3->setVisible(0);
    ui->pushButton_19->setVisible(0);
    id=1;
    ui->pushButton_4->setVisible(0);
    ui->pushButton_5->setVisible(0);
    ui->pushButton_11->setVisible(0);




}

Terrinet::~Terrinet()
{
    delete ui;
}

void Terrinet::on_topics_clicked()
{
    move = new Movement(this);
    move->show();
}

void Terrinet::on_pushButton_clicked()
{
    //QProcess builder;
    std::cout<<"RX90"<<std::endl;
    system("gnome-terminal -x bash -c 'killall gzclient;source ~/ws_rx90/devel/setup.bash; roslaunch rx90_description double_rx90.launch'");
}

void Terrinet::on_pushButton_2_clicked()
{
    std::cout<<"PIONEER"<<std::endl;
    system("gnome-terminal -x bash -c 'killall gzclient;export ROS_PACKAGE_PATH=/home/luis/ws_p3at/src:/home/luis/ws_agv_golf/src:/home/luis/ws_ual/src:/opt/ros/kinetic/share; roslaunch pioneer3at pioneer3at.launch'");





}

void Terrinet::on_pushButton_12_clicked()
{
    std::cout<<"BOBCAT"<<std::endl;
    system("gnome-terminal -x bash -c 'killall gzclient;source ~/ws_agv_golf/devel/setup.bash & source ~/ws_ual/devel/setup.bash; roslaunch rbcar_sim_bringup rbcar_complete_gs.launch'");



}

void Terrinet::on_pushButton_20_clicked()
{
    std::cout<<"AGV"<<std::endl;
    system("gnome-terminal -x bash -c 'killall gzclient;source ~/ws_agv_golf/devel/setup.bash & source ~/ws_ual/devel/setup.bash; roslaunch ackermann_gazebo ackermann_vehicle.launch'");


}

void Terrinet::on_pushButton_3_clicked()
{
    std::cout<<"UAL hecatonquiros"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_4_clicked()
{
    std::cout<<"RRT"<<std::endl;
    system("gnome-terminal -x bash -c 'source ~/ws_p3at/devel/setup.bash; roslaunch pioneer3at algorithms.launch algorithm:=1'");

}

void Terrinet::on_pushButton_5_clicked()
{
    std::cout<<"RRT*"<<std::endl;
    system("gnome-terminal -x bash -c 'source ~/ws_p3at/devel/setup.bash; roslaunch pioneer3at algorithms.launch algorithm:=2'");

}


void Terrinet::on_pushButton_6_clicked()
{
    std::cout<<"Mbzirc"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch robot_model:=mbzirc description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_7_clicked()
{
    std::cout<<"Typhoon"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch robot_model:=typhoon_h480 description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_8_clicked()
{
    std::cout<<"Iris"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch robot_model:=iris description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);



}

void Terrinet::on_pushButton_9_clicked()
{
    std::cout<<"Aeroarms"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch robot_model:=aeroarms description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}



void Terrinet::on_pushButton_10_clicked()
{
    std::cout<<"Aeroarms pendulum"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch uav_abstraction_layer test_server.launch robot_model:=aeroarms_pendulum description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_11_clicked()
{

    std::cout<<"TSP algorithm"<<std::endl;
    //pongo el launcher despues de crear el archivo
    //system("gnome-terminal -x bash -c 'source ~/ws_ual/devel/setup.bash; rosrun tsp_mtsp test_ual_interfaces_mtsp'");
    //ui->label_3->setVisible(1);
    //ui->label_4->setVisible(1);
    //ui->label_5->setVisible(1);
    ui->commandLinkButton->setVisible(1);
    ui->lineEdit_2->setVisible(1);
    ui->lineEdit->setVisible(1);
    ui->lineEdit_3->setVisible(1);
    ui->pushButton_19->setVisible(1);



}

void Terrinet::on_pushButton_11_clicked(bool checked)
{


}


void Terrinet::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->comboBox->currentText() == "Px4 bringup"){
        ui->pushButton_3->setVisible(0);
        ui->pushButton_6->setVisible(0);
        ui->pushButton_7->setVisible(0);
        ui->pushButton_8->setVisible(0);
        ui->pushButton_9->setVisible(0);
        ui->pushButton_10->setVisible(0);

        ui->pushButton_13->setVisible(1);
        ui->pushButton_14->setVisible(1);
        ui->pushButton_15->setVisible(1);
        ui->pushButton_16->setVisible(1);
        ui->pushButton_17->setVisible(1);
        ui->pushButton_18->setVisible(1);
    }
    else{
        ui->pushButton_3->setVisible(1);
        ui->pushButton_6->setVisible(1);
        ui->pushButton_7->setVisible(1);
        ui->pushButton_8->setVisible(1);
        ui->pushButton_9->setVisible(1);
        ui->pushButton_10->setVisible(1);

        ui->pushButton_13->setVisible(0);
        ui->pushButton_14->setVisible(0);
        ui->pushButton_15->setVisible(0);
        ui->pushButton_16->setVisible(0);
        ui->pushButton_17->setVisible(0);
        ui->pushButton_18->setVisible(0);

    }

}

void Terrinet::on_pushButton_13_clicked()
{
    std::cout<<"UAL hecatonquiros"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);

}

void Terrinet::on_pushButton_14_clicked()
{
    std::cout<<"Mbzirc"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch robot_model:=mbzirc description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_15_clicked()
{
    std::cout<<"Iris"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient; source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch robot_model:=iris description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);

}

void Terrinet::on_pushButton_16_clicked()
{
    std::cout<<"Typhoon"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient; source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch robot_model:=typhoon_h480 description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_17_clicked()
{
    std::cout<<"Aeroarms"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch robot_model:=aeroarms description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);
}

void Terrinet::on_pushButton_18_clicked()
{
    std::cout<<"Aeroarms pendulum"<<std::endl;
    std::string cadena="gnome-terminal -x bash -c 'killall gzclient;  source ~/ws_ual/devel/setup.bash; roslaunch px4_bringup test_simulate.launch robot_model:=aeroarms_pendulum description_package:=robots_description world:=empty_light id:=";
    cadena=conv(cadena);
    const char *c_cadena = cadena.c_str();
    system(c_cadena);

}

void Terrinet::on_pushButton_19_clicked()
{
    int i;
    const char *path="/home/luis/ws_ual/src/grvc-ual/tsp_mtsp/src/pos.txt";
    std::ofstream file(path);
    //file.open("test.txt");
    for(i=0;i<cnt;i++)
    {
        file << x[i] << std::endl;
        file << y[i] << std::endl;
        file << z[i] << std::endl;
        //std::cout<<x[i]<<y[i]<<z[i]<<std::endl;
    }

    file.close();
    //ui->label_3->setVisible(0);
    //ui->label_4->setVisible(0);
    //ui->label_5->setVisible(0);
    ui->commandLinkButton->setVisible(0);
    ui->lineEdit_2->setVisible(0);
    ui->lineEdit->setVisible(0);
    ui->lineEdit_3->setVisible(0);
    ui->pushButton_19->setVisible(0);
    system("gnome-terminal -x bash -c 'source ~/ws_ual/devel/setup.bash; rosrun tsp_mtsp test_ual_interfaces_mtsp'");

}

void Terrinet::on_commandLinkButton_clicked()
{

    QString qx,qy,qz;
    qx=ui->lineEdit->text();
    qy=ui->lineEdit_2->text();
    qz=ui->lineEdit_3->text();
    x[cnt]=qx.toInt();
    y[cnt]=qy.toInt();
    z[cnt]=qz.toInt();
    cnt++;

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}


std::string Terrinet::conv(std::string cadena){

    std::string id_string;
    std::stringstream ss;
    ss << id;
    id_string = ss.str();
    cadena=cadena+id_string+"'";
    std::cout<<cadena<<std::endl;
    id++;
    return cadena;
}
