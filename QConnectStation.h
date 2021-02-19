#ifndef QCONNECTSTATION_H
#define QCONNECTSTATION_H

#include <QMap>
#include "QNode.h"

class QNode;

class QConnectStation{
private:
    QMap<int,QNode> allSignals;
    QConnectStation();
public:
    static QConnectStation& getInstance();
    int registerSignal(const QObject* obj , const char* signalName , int signalIndex);
    int connectToSignal(const QObject* obj , const char* signalName , int signalIndex);
};

#endif // QCONNECTSTATION_H
