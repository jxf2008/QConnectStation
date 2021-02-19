#ifndef QNODE_H
#define QNODE_H

#include <QObject>

class QNode{
private:
    const QObject* owner_Object;
    const char* methodPtr;
public:
    QNode();
    QNode(const QObject* owner ,const char* ptr);
    ~QNode();
    QNode(const QNode& other){owner_Object = other.owner_Object;methodPtr = other.methodPtr;}
    QNode(QNode&& other){owner_Object = other.owner_Object;methodPtr = other.methodPtr;}
    QNode& operator=(const QNode& other){owner_Object = other.owner_Object;methodPtr = other.methodPtr;return *this;}
    QNode& operator=(QNode&& other){owner_Object = other.owner_Object;methodPtr = other.methodPtr;return *this;}
    const QObject* getOwnerObject()const;
    const char* getMethodPtr()const;
};

#endif // QNODE_H
