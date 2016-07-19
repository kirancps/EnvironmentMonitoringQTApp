#include "serialcomm.h"
#include "ui_serialcomm.h"
#include <QSerialPort>
#include <QDebug>
#include <QtWidgets>
#include <QDate>
#include<QTimer>
#include <QtMultimedia>
#include <QMediaPlayer>
int i=0;

QSerialPort *serial;
QMovie *movie;
QTimer *timer;
QMediaPlayer *player;

QPropertyAnimation* mMoveAnimation;
serialComm::serialComm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serialComm)
{
    ui->setupUi(this);

player=new QMediaPlayer;
    QImage sw1;
    sw1.load("/home/designer/SerialCommunication/sw2.jpg");
    ui->label_2->setPixmap(QPixmap::fromImage(sw1));
    ui->label_2->show();
    QImage sw2;
    sw2.load("/home/designer/SerialCommunication/sw1.jpg");
    ui->label_6->setPixmap(QPixmap::fromImage(sw2));
    ui->label_6->show();
    timer=new QTimer(this);
    movie = new QMovie(this);
    movie->setCacheMode(QMovie::CacheAll);
    ui->label_3->setAlignment(Qt::AlignCenter);

    //movieLabel = new QLabel(tr("No movie loaded"));
    ui->label_4-> setAlignment(Qt::AlignCenter);
    ui->label_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_4->setBackgroundRole(QPalette::Dark);
    ui->label_4->setAutoFillBackground(true);
    ui->label_4->setScaledContents(true);

//    ui->label_2->setAlignment( Qt::AlignCenter);

    ui->label_4->setMovie(movie);


    QStringList addr;
    addr <<"/home/designer/Pictures/smart/a.gif"<<"/home/designer/Pictures/smart/b.gif";

       movie->setFileName("/home/designer/Pictures/smart/a.gif");


    connect (timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(5000);
     movie->start();

   // movie->start();






//    mMoveAnimation = new QPropertyAnimation(ui->label_2, "rotation");
//    mMoveAnimation->setDuration(100);
//    mMoveAnimation->setStartValue(100);
//    mMoveAnimation->setEndValue(150);

//    mMoveAnimation->start();


























    serial=new QSerialPort(this);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setPortName("/dev/ttyUSB0");
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadWrite);
    //serial->write("ok");
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialRead()));



    
}

serialComm::~serialComm()
{
    delete ui;
    serial->close();
}

void serialComm::serialRead(){

    QString str;
    int  len=0;


    str=serial->readAll();
    len=str.length();
   qDebug()<<str<<len;
   if(len<2){
   len=2;
   }
    if (str[0]=='R'){



       ui->label_3->setText("PM2.5"+str.right(len-1).append("%"));
       ui->label->setText("Keep Your City Clean");

       player->setMedia(QUrl::fromLocalFile("/home/designer/SerialCommunication/pm2.wav"));

       player->setVolume(50);
       player->play();




        //ui->label_2->setText(str);


   }
    if (str[0]=='A'){



       ui->label_3->setText("Carbon monoxide "+str.right(len-1).append(" ppm"));
       ui->label->setText("Keep Your City Clean");

       player->setMedia(QUrl::fromLocalFile("/home/designer/SerialCommunication/co.wav"));

       player->setVolume(50);
       player->play();




        //ui->label_2->setText(str);


   }




    if (str[0]=='B'){
         ui->label_3->setText("Carbon dioxide "+str.right(len-1)+" ppm");
           ui->label->setText("Be Fair, Don’t Pollute The Air");
           player->setMedia(QUrl::fromLocalFile("/home/designer/SerialCommunication/co2.wav"));

           player->setVolume(50);
           player->play();



    }



    if (str[0]=='H'){
         ui->label_3->setText("Humidity "+str.right(len-1)+" %");
           ui->label->setText("Using Plastic Is Going To Be Drastic");




    }


    if (str[0]=='T'){
         ui->label_3->setText("Temperature "+str.right(len-1)+" 'C");
           ui->label->setText("If You Litter, The Future Will Be Bitter");




    }


    if (str[0]=='D'){
         ui->label_3->setText("Dew Point "+str.right(len-1)+"'C");
           ui->label->setText("Wipe Out Pollution Before It Wipes You Out");




    }



    if (str[0]=='L'){
         ui->label_3->setText("Methane "+str.right(len-1)+" ppm");
           ui->label->setText("Care For Air, Polluting It Is Not Fair");




    }


    if (str[0]=='S'){
         ui->label_3->setText("Smoke Gas "+str.right(len-1)+" ppm");
           ui->label->setText("Be Fair, Don’t Pollute The Air");




    }




}


void serialComm::update(){



movie->stop();
if(i>=0){
movie->setFileName("/home/designer/Pictures/smart/b.gif" );
i--;
}

else {
  movie->setFileName("/home/designer/Pictures/smart/a.gif" );
  i++;
}




 movie->start();



}
