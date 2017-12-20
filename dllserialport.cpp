#include "dllserialport.h"


DLLSerialPort::DLLSerialPort()
{
    serial = new QSerialPort(this);
    this->openSerialPort();
}

void DLLSerialPort::openSerialPort()
{
    serial->setPortName("../../COM3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    //serial->setFlowControl(QSerialPort::HardwareControl);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite))
    {
        connect(serial, SIGNAL(readyRead()), this, SLOT(readCard()));
    }
    else
    {
        qDebug() << "Portin avaaminen ei onnistunut!";
    }
}

void DLLSerialPort::closeSerialPort()
{
    serial->close();
}

void DLLSerialPort::readCard()
{
    QString data;
    data = serial->readAll();
    data.remove(0,3);
    data.chop(3);

    cardSerialNumber="";
    cardSerialNumber=data;

    emit serialDataRead();
}

QString DLLSerialPort::returnCardNumber()
{
    return cardSerialNumber;
}
