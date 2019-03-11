#ifndef TERRINET_H
#define TERRINET_H
#include <fstream>
#include <iostream>

#include <QWidget>
#include "movement.h"

namespace Ui {
class Terrinet;
}

class Terrinet : public QWidget
{
    Q_OBJECT

public:
    explicit Terrinet(QWidget *parent = 0);
    int id;
    ~Terrinet();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_11_clicked(bool checked);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_commandLinkButton_clicked();

    void on_topics_clicked();



private:

    Ui::Terrinet *ui;    
    int x[100],y[100],z[100];
    int cnt=0;
    //
    std::string conv(std::string cadena);
    Movement *move;





};

#endif // TERRINET_H
