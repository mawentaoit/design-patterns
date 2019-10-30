/*
模式动机：
对于系统中的某些类来说，只有一个实例很重要，例如，一个系统中可以存在很多个打印任务，但是只能有一个正在
工作的任务；一个系统只能有一个窗口管理器或文件系统；一个系统只能有一个计时工具或ID生成器

如何保证一个类只有一个实例并且这个实例易于被访问呢？定义一个全局变量可以确保对象随时都可以被
访问，但不能防止我们实例化多个对象。

一个更好的解决办法是让类自身负责保存它的唯一实例。这个类可以保证没有其他实例被创建，并且它可以提供一个访问
该实例的方法。这就是单例模式的模式动机。
*/
#include <iostream>
class singleton {
public:
    ~singleton();
    static singleton* getInstance() ;
    void singletonOperator() const;
private:
    singleton();
    static singleton* instance ; 
};
singleton* singleton::instance = nullptr;
singleton::singleton() {

}
singleton::~singleton() {
    delete instance;
}
singleton* singleton::getInstance() {
    if (instance == nullptr) {
        instance = new singleton();
    }
    return instance;
}

void singleton::singletonOperator() const {
    std::cout << "singletonOperation" << std::endl;
}

int main() {
    singleton* sg = singleton::getInstance();
    sg->singletonOperator();

    return 0;
}

/*
单例类的构造函数为私有
提供一个自身的静态私有成员变量
提供一个共有的静态工厂方法
*/
/*
优点
1 提供了对唯一实例的受控访问
2 可以节约系统资源，对于一些需要频繁创建和销毁的对象，单例模式无疑可以提高系统的性能
3 允许可变数目的实例，我们可以对单例模式进行扩展
*/
/*
缺点：
1 单例模式没有抽象层，不容器扩展
2 职责过重，单例类既充当了工厂角色，也提供了工厂方法
*/