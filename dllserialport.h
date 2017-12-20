#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "dllserialport_global.h"
#include <QtSerialPort/QtSerialPort>
#include <QObject>
#include <QDebug>
#include <QString>

class DLLSerialPort : public QObject
{
    Q_OBJECT
public:
    DLLSERIALPORTSHARED_EXPORT DLLSerialPort();
    void openSerialPort();
    void DLLSERIALPORTSHARED_EXPORT closeSerialPort();
    QString DLLSERIALPORTSHARED_EXPORT returnCardNumber();

public slots:
     void readCard();

signals:
     void serialDataRead();

private:
    QString cardSerialNumber;
    QSerialPort *serial;
};

#endif // DLLSERIALPORT_H
