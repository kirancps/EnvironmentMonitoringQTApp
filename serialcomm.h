#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

namespace Ui {
class serialComm;
}

class serialComm : public QMainWindow
{
    Q_OBJECT

public:
    explicit serialComm(QWidget *parent = 0);
    ~serialComm();


private slots:

    void serialRead();
    void update();

private:
    Ui::serialComm *ui;
};

#endif // SERIALCOMM_H
