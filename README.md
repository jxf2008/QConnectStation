## 用途

对于一些较为复杂的Qt程序来说，随着Qt类的嵌套深度越来越大，信号与槽的连接也变得越来越麻烦，距离，一个类A1，他有类成员A2，A2有类成员A3.在程序中还有一个类B1，该类有个类成员为B2，而B2有个类成员B3，如果A3有个信号需要和B3连接，就进行以下步骤

1. A3信号与A2信号连接
2. A2信号与A1信号连接
3. B1信号与A1信号连接
4. B2信号与A1信号连接
5. B2信号与B3槽连接

也就是说，为了连接这（A3的）信号与（B3的）槽，需要在类A1,A2,B1,B2中定义信号，并使得他们逐个连接。在较大的Qt项目中，这种需求往往很常见，而且会导致代码膨胀，且维护困难，为了解决这个问题，这里将Qt原生的信号与槽的连接方式加以封装，提供一种简单的直连方法。

## 示例

使用该功能需要包含头文件QConnectStation.h，该头文件提供了QconnectStation类的定义。

### 注册信号
```c++
QConnectStation::getInstance().registerSignal(click_PushButton,SIGNAL(clicked()),1);
```
这里通过registerSignal()将信号注册，该函数第3个参数为int类型（建议使用枚举值），为注册信号的唯一索引，如果已经注册的信号已经使用了某一索引，则信号会注册失败。registerSignal()函数的返回值为0时表示注册成功，1为注册失败（该索引已有信号使用）

## 将槽与信号连接
```c++
QConnectStation::getInstance().connectToSignal(this,SLOT(showText()),1);
```
该函数的第3个参数同样是信号索引，该函数将槽和索引对应的信号连接起来，如果没有该索引对应的信号，connectToSignal()返回1，如果连接成功，返回0。connectToSignal()函数还有第四个参数，为默认值Qt::ConnectionType type = Qt::AutoConnection。