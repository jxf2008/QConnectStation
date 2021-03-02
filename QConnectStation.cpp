#include "QConnectStation.h"

QConnectStation::QNode::QNode(){
    owner = nullptr;
    methodPtr = nullptr;
}

QConnectStation::QNode::QNode(const QObject* owner , const char* ptr){
    this->owner = owner;
    methodPtr = ptr;
}

QConnectStation::QNode::~QNode(){

}

QConnectStation::QConnectStation(){

}

QConnectStation& QConnectStation::getInstance(){
    static QConnectStation A;
    return A;
}

int QConnectStation::registerSignal4(const QObject* obj , const char* signalName , int signalIndex){
    int status = 0;
    if(allSignals.keys().contains(signalIndex)){
        status = -1;
        return status;
    }

    QNode node(obj,signalName);
    allSignals.insert(signalIndex,node);
    return status;
}

int QConnectStation::connectToSignal4(const QObject* obj , const char* signalName , int signalIndex , Qt::ConnectionType type){
    int status = 0;
    if(!allSignals.keys().contains(signalIndex)){
        status = -1;
        return status;
    }

    QNode node = allSignals.value(signalIndex);
    QObject::connect(node.getOwnerObject(),node.getMethodPtr(),obj,signalName,type);
    return status;
}


















































