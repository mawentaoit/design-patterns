/*
模式动机
设想如果要绘制矩形，圆形，椭圆，正方形，我们至少需要4个形状类，
但是如果绘制的图形需要具有不同的颜色，如红色、绿色、蓝色等，此时至少有如下两种设计方案：

* 第一种设计方案是为每一种形状都提供一套各种颜色的版本。
* 第二种设计方案是根据实际需要对形状和颜色进行组合
对于有两个变化维度的系统，采用方案二来进行设计系统中类的个数更少，且系统扩展更为方便。
设计方案二即是桥接模式的应用。桥接模式将继承关系转换为关联关系，从而降低了类与类之间的耦合，
减少了代码编写量
*/

/* 
桥接模式：将抽象部分与它实现部分分离，使它们都可以独立地变化。它是一种对象结构型模式，又称为柄体模式
或接口模式
*/

/*
桥接模式包含如下角色:
1 Abstraction: 抽象类
2 RefinedAbstraction: 扩充抽象类
3 Implementor:    实现类接口
4 ConcreteImplementor: 具体实现类
*/
#include <iostream>


//抽象实现类
class Implement {
public:
    virtual void Operation() = 0; //定义操作接口
    virtual ~Implement();
protected:
    Implement();
};
Implement::Implement() {}
Implement::~Implement() {}

//继承自Implement,是Implement的不同实现之一
class ConcreteImplementorA : public Implement {
public:
    ConcreteImplementorA();
    void Operation(); //实现操作
    ~ConcreteImplementorA();
};
ConcreteImplementorA::ConcreteImplementorA() {}
ConcreteImplementorA::~ConcreteImplementorA() {}
void ConcreteImplementorA::Operation() {
    std::cout << "ConcreteAbstractionImplementA Operation" << std::endl;
}

//继承自Implement, 是Implement的不同实现之一
class ConcreteImplementorB : public Implement {
public:
    ConcreteImplementorB();
    void Operation(); //实现操作
    ~ConcreteImplementorB();
};
ConcreteImplementorB::ConcreteImplementorB() {}
ConcreteImplementorB::~ConcreteImplementorB() {}
void ConcreteImplementorB::Operation() {
    std::cout << "ConcreteAbstractionImplementB Operation" << std::endl;
}


//抽象类
class Abstraction {
public:
    virtual void Operation() = 0; //定义接口，表示该类所支持的操作
    virtual ~Abstraction();
protected:
    Abstraction();
};
Abstraction::Abstraction() {}
Abstraction::~Abstraction() {}


//扩充抽象类A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implement* imp);
    virtual void Operation(); //实现接口
    virtual ~RefinedAbstractionA(); //析构函数
private:
    Implement* _imp; //私有成员
};
RefinedAbstractionA::RefinedAbstractionA(Implement* imp) {
    this->_imp = imp;
}
RefinedAbstractionA::~RefinedAbstractionA() {
    delete this->_imp;
    this->_imp = NULL;
}
void RefinedAbstractionA::Operation() {
    std::cout << "RefinedAbstractionA::Operation" << std::endl;
    this->_imp->Operation();
}

//扩充抽象类B
class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(Implement* imp); //构造函数
    virtual void Operation(); //实现接口
    virtual ~RefinedAbstractionB(); //析构函数
private:
    Implement* _imp; //私有成员
};
RefinedAbstractionB::RefinedAbstractionB(Implement* imp) {
    std::cout << "RefinedAbstractionB::Operation" << std::endl;
    this->_imp->Operation();
}
RefinedAbstractionB::~RefinedAbstractionB() {
    delete this->_imp;
    this->_imp = NULL;
}
void RefinedAbstractionB::Operation() {
    std::cout << "RefinedAbstractionB::Operation" << std::endl;
   this->_imp->Operation();    
}


int main() {
    Implement* imp = new ConcreteImplementorA(); //实现部分
    Abstraction* abs = new RefinedAbstractionA(imp); //抽象部分
    abs->Operation();

    std::cout << "==================================" << std::endl;

    Implement* imp1 = new ConcreteImplementorB(); //实现部分
    Abstraction* abs1 = new RefinedAbstractionA(imp1); //抽象部分
    abs1->Operation();
}

