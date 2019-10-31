/*
一般有两种方式可以实现给一个类或对象增加行为：
1 继承机制，使用继承机制是给现有类添加功能的一种有效途径。
2 关联机制，即将一个类的对象嵌入另一个对象中，由另一个对象来决定是否调用嵌入
对象的行为以便扩展自己的行为，我们称这个嵌入的对象为装饰器

模式定义
装饰模式：动态地给一个对象增加一些额外的职责，就增加对象功能来说，装饰模式比生成子类实现更为灵活。
其别名也可以称为包装器。

模式结构：
1 Component: 抽象构件
2 ConcreteComponent: 具体构件
3 Decorator: 抽象装饰类
4 ConcreteDecorator: 具体装饰类

例子：有多种手机，允许你为手机添加特性，比如增加挂件，屏幕贴膜等。一种灵活的设计方式是，将手机嵌入
到另一个对象中，由这个对象完成特性的添加，我们称这个嵌入的对象为装饰。这个装饰与它所装饰
的组件接口一致，因此它对使用该组件的客户透明。
*/

#include <iostream>
//公共抽象类
class phone {
public:
    phone();
    virtual ~phone();
    virtual void showMessage() = 0;
};
phone::phone() {}
phone::~phone() {
    std::cout << "phone 析构掉了" << std::endl;
}

class iphone : public phone {
public:
    iphone();
    ~iphone();
    void showMessage();
};
iphone::~iphone() {
    std::cout << "iphone 析构掉了" << std::endl;
}
iphone::iphone() {}
void iphone::showMessage() {
    std::cout << "我是iphone" << std::endl;
}

class huawei : public phone {
public:
    huawei();
    ~huawei();
    void showMessage();
};
huawei::~huawei() {}
huawei::huawei() {}
void huawei::showMessage() {
    std::cout << "我是huawei" << std::endl;
}

//抽象装饰器
class Decorator {
public:
    Decorator();
    ~Decorator();
    virtual void showMessage()  = 0; //抽象接口的行为

};
Decorator::Decorator() {}
Decorator::~Decorator() {
    std::cout << "抽象装饰器析构完成" << std::endl;
}

//屏幕保护装置者
class screenProtectDecorator : Decorator {
public:
    screenProtectDecorator(phone* p);
    ~screenProtectDecorator();
    void showMessage();
    void tiepingmu();
private:
    phone* _phone;
};
screenProtectDecorator::screenProtectDecorator(phone* p) {
    std::cout << "屏幕保护装饰器创建完成" << std::endl;
    this->_phone = p;
}
screenProtectDecorator::~screenProtectDecorator() {
    std::cout << "屏幕保护装饰器析构完成" << std::endl;
    delete this->_phone;
    this->_phone = NULL; 
}
void screenProtectDecorator::showMessage() {
    this->_phone->showMessage();
}
void screenProtectDecorator::tiepingmu() {
    std::cout << "我正在贴屏幕" << std::endl;
}

int main() {
    phone* p1 = new huawei();
    phone* p2 = new iphone();
    screenProtectDecorator s1(p1);
    screenProtectDecorator s2(p2);
    s1.showMessage();
    s1.tiepingmu();

    s2.showMessage();
    s2.tiepingmu();
}

/*与继承相比，关联关系的主要优势在于不会破坏类的封装性，而且继承是一种耦合度较大的静态关系，
无法在程序运行时动态扩展。在软件开发阶段，关联关系虽然不会比继承减少代码量，但是到了
软件维护阶段，由于关联关系使系统具有较好的松耦合性，因此使得系统更加容易维护

优点：
装饰模式与继承关系的目的都是要扩展对象的功能，但是装饰模式可以提供比继承更多的灵活性。
可以通过一种动态的方式来扩展一个对象的功能，通过配置文件可以在运行时选择不同的装饰器，从而实现不同的行为
通过使用不同的具体装饰类以及这些装饰类的排列组合，可以创造出很多不同行为的组合。

缺点：
使用装饰模式进行系统设计时将产生好多小对象，这些对象的区别在于它们之间相互连接的方式有所不同，而不是它们的
类或者属性值有所不同，同时还将产生很多具体装饰类。这些装饰类和小对象的产生将增加系统的复杂度，加大学习与
理解的难度
这种比继承更加灵活的特性，也同时意味着装饰模式比继承更加易于出错，排错也很困难，对于多次装饰的对象，
调试时寻找错误可能需要逐级排查，较为繁琐。
*/