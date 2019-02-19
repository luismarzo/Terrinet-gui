#include "terrinet.h"
#include <QApplication>
#include <QProcess>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Terrinet w;
    w.show();

    return a.exec();
}
