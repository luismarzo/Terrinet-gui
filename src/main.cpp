#include "terrinet.h"
#include "movement.h"
#include <QApplication>
#include <QProcess>
#include <ros/ros.h>
#include <iostream>
#include <thread>
#include <chrono>


int main(int argc, char **argv)
{

    ros::init(argc, argv, "terrinet_gui");

     std::thread spinThread([&](){
     ros::spin();
     }); //now we can use subscribers and publishers

    QApplication a(argc, argv);
    Terrinet w;
    w.show();

    return a.exec();
}
