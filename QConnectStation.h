#ifndef QCONNECTSTATION_H
#define QCONNECTSTATION_H

#include <QObject>
#include <QMap>

class QConnectStation{
private:
    class QNode{
    private:
        const QObject* owner;
        const char* methodPtr;
    public:
        QNode();
        QNode(const QObject* owner ,const char* ptr);
        QNode(const QObject* owner ,const void* ptr);
        ~QNode();
        QNode(const QNode& other){owner = other.owner;methodPtr = other.methodPtr;}
        QNode(QNode&& other){owner = other.owner;methodPtr = other.methodPtr;}
        QNode& operator=(const QNode& other){owner = other.owner;methodPtr = other.methodPtr;return *this;}
        QNode& operator=(QNode&& other){owner = other.owner;methodPtr = other.methodPtr;return *this;}
        const QObject* getOwnerObject()const{return owner;}
        const char* getMethodPtr()const{return methodPtr;}
    };
    QMap<int,QNode> allSignals;
    QConnectStation();
public:
    QConnectStation(const QConnectStation& other)=delete;
    QConnectStation& operator=(const QConnectStation& other)=delete;
    static QConnectStation& getInstance();
    int registerSignal4(const QObject* obj , const char* signalName , int signalIndex);
    int connectToSignal4(const QObject* obj , const char* signalName , int signalIndex , Qt::ConnectionType type = Qt::AutoConnection);
};

#endif // QCONNECTSTATION_H
