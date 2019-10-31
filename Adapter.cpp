/*
适配器模式

* 在软件开发中采用类似于电源适配器的设计和编码技巧被称为适配器模式
* 将一个接口转换成客户希望的另一个接口，适配器模式使用接口不兼容的那些类
可以一起工作，其别名为包装器。适配器模式既可以作为类结构模式，也可以作为对象结构型模式。
*/

/*
模式包含如下角色：
* Target: 目标抽象类
* Adapter: 适配器类
* Adaptee: 适配者类
* Client: 客户端类
*/

#include <iostream>
//适配者类
class Adaptee {
public:
    Adaptee();
    virtual ~Adaptee();
    void specificRequest();
};
Adaptee::Adaptee() {

}
Adaptee::~Adaptee() {

}
void Adaptee::specificRequest() {
    std::cout << "我是适配者的成员函数" << std::endl;
}

//目标抽象类
class Target {
public:
    virtual ~Target() {};
    virtual void request() = 0; 
};

//适配器类
class Adapter : public Target {
public:
    Adapter(Adaptee *adaptee);
    virtual ~Adapter();
    virtual void request();
private:
    Adaptee* m_pAdaptee;
};
Adapter::Adapter(Adaptee* adaptee) : m_pAdaptee(adaptee) {}
Adapter::~Adapter() {};
void Adapter::request() {
    m_pAdaptee->specificRequest();
}



int main() {
    Adaptee* adaptee = new Adaptee();
    Target* tar = new Adapter(adaptee);
    tar->request();
}

/*
优点
1 将目标类和适配者类解耦，通过引入一个适配类来重用现有的适配者类，而无须修改原有代码。
2 增加了类的透明性和复用性，将具体的实现封装在适配者类中，对于客户端类来说是透明的，而且提高了适配者的复用性
3 灵活性和扩展性都非常好，通过使用配置文件，可以很方便地更换适配器，也可以在不修改原有代码的基础上
增加新的适配器类，完全符合“开闭原则”

缺点：
与类适配器模式相比，想要置换适配者类的方法就不容易。如果一定要置换掉适配者类的一个或多个方法，就只好先做一个
适配者类的子类，将适配者类的方法置换掉，然后再把适配者类的子类当作真正的适配者进行适配
*/

/* 
模式应用JDBC, JDBC给出一个客户通用的抽象接口，每一个具体数据库引擎的JDBC驱动软件都是一个介于JDBC接口
和数据库引擎接口之间的适配器软件。抽象的JDBC接口和各个数据库引擎API之间都需要相应的适配器软件，
这就是为各个不同数据引擎准备的驱动程序
*/

/*
模式扩展
缺省适配器模式
当不需要全部实现接口提供的方法时，可以先设计一个抽象类实现接口，并为该接口中每个方法提供一个默认实现
，那么该抽象类的子类可有选择地覆盖父类的某些方法来实现需求，它适用于一个接口不想使用其所有的方法的情
况。因此也称为单接口适配器模式。
*/
