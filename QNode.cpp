#include "QNode.h"

QNode::QNode(){
    owner_Object = nullptr;
    methodPtr = nullptr;
}

QNode::QNode(const QObject* owner , const char* ptr){
    owner_Object = owner;
    methodPtr = ptr;
}
QNode::~QNode(){

}

const QObject* QNode::getOwnerObject()const{
    return owner_Object;
}

const char* QNode::getMethodPtr()const{
    return methodPtr;
}
