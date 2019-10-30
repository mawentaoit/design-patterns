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
    singleton();
    ~singleton();
    static singleton* getInstance() ;
    void singletonOperator() const;
private:
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

