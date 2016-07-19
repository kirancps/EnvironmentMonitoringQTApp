#include "serialcomm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialComm w;
    w.show();
    //w.showFullScreen();



    return a.exec();
}
