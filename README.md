## 用途

对于一些较为复杂的Qt程序来说，随着Qt类的嵌套深度越来越大，信号与槽的连接也变得越来越麻烦，举例，一个类A1，他有类成员A2，A2有类成员A3.在程序中还有一个类B1，该类有个类成员为B2，而B2有个类成员B3，如果A3有个信号需要和B3连接，就进行以下连接

>A3->A2->A1->B1->B2->B3

也就是说，为了连接这（A3的）信号与（B3的）槽，需要在类A1,A2,B1,B2中定义信号，并使得他们逐个连接。在较大的Qt项目中，这种需求往往很常见，而且会导致代码膨胀，维护困难，为了解决这个问题，这里将Qt原生的信号与槽的连接方式加以封装，提供一种简单的直连方法。

使用该功能需要包含头文件QConnectStation.h，该头文件提供了QconnectStation类的定义。

### 注册信号
```c++
int registerSignal4(const QObject* obj , const char* signalName , int signalIndex);
```
这里通过registerSignal()将信号注册，该函数第3个参数为int类型（建议使用枚举值），为注册信号的唯一索引，如果已经注册的信号已经使用了某一索引，则信号会注册失败。registerSignal()函数的返回值为0时表示注册成功，1为注册失败（该索引已有信号使用）,调用示例如下
```c++
QConnectStation::getInstance().registerSignal4(show_PushButton,SIGNAL(clicked()),SHOW_PUSHBUTTON_CLICK);
```

## 将槽与信号连接
```c++
int connectToSignal4(const QObject* obj , const char* signalName , int signalIndex , Qt::ConnectionType type = Qt::AutoConnection);
```
该函数的第3个参数signalIndex同样是信号索引，该函数将槽和索引对应的信号连接起来，如果没有该索引对应的信号，connectToSignal()返回1，如果连接成功，返回0。connectToSignal()函数还有第四个参数，为默认值Qt::ConnectionType type = Qt::AutoConnection，该参数用于信号与槽的连接选项，详细参见QObject的connect()函数对于该值的说明。调用示例如下
```c++
QConnectStation::getInstance().connectToSignal4(this,SLOT(showText()),SHOW_PUSHBUTTON_CLICK);
```
这里将槽showText()和索引SHOW_PUSHBUTTON_CLICK对应的信号（示例中是show_PushButton的clicked()信号）连接起来，这里使得开发人员无需关心信号在哪个类里，无论this和show_PushButton这两个对象位于什么位置，只要两行代码（调用注册函数和连接函数），即可将两个对象的信号与槽连接起来。