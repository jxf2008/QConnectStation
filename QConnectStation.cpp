#include "QConnectStation.h"

QConnectStation::QConnectStation(){

}

QConnectStation& QConnectStation::getInstance(){
    static QConnectStation A;
    return A;
}

int QConnectStation::registerSignal(const QObject* obj , const char* signalName , int signalIndex){
    int status = 0;
    if(allSignals.keys().contains(signalIndex)){
        status = -1;
        return status;
    }

    QNode node(obj,signalName);
    allSignals.insert(signalIndex,node);
    return status;
}

int QConnectStation::connectToSignal(const QObject* obj , const char* signalName , int signalIndex){
    int status = 0;
    if(!allSignals.keys().contains(signalIndex)){
        status = -1;
        return status;
    }

    QNode node = allSignals.value(signalIndex);
    QObject::connect(node.getOwnerObject(),node.getMethodPtr(),obj,signalName);
}

















































