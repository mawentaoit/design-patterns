/**
 * 简单工厂模式
 * 可以根据不同的参数返回不同类的实例。
 *
 */

/* 模式结构
1 Factory: 工厂角色(负责实现创建所有实例的内部逻辑)
2 Product: 抽象产品角色(创建所有能创建对象的父类，描述所有实例所共有的公共接口)
3 ConcreteProduct: 具体产品角色(所有创建的对象都是这个具体类的实例)
*/

#include <iostream>
#include <string>

/**
 * 抽象产品角色
 */
class Book {
public:
    virtual void printInfo() = 0;
};


/**
 * 具体产品角色
 */
class MathBook : public Book {
public:
    void printInfo();
};

void MathBook::printInfo() {
    std::cout << "我是一本数学书" << std::endl;
}

class EnglishBook : public Book {
public:
    void printInfo();
};
void EnglishBook::printInfo() {
    std::cout << "我是一本英语书" << std::endl;
}


/**
 * 工厂角色
 */
class BookFactory {
public:
    Book* CreateBook (std::string bookMsg) const;
};
Book* BookFactory::CreateBook (std::string bookMsg) const{
        if (bookMsg == "math") {
            return new MathBook();
        } 
        else if (bookMsg == "english") {
            return new EnglishBook();
        }
        return NULL;
}

int main() {
    BookFactory bf;
    Book* b1 = bf.CreateBook("math");
    Book* b2 = bf.CreateBook("english");

    b1->printInfo();
    b2->printInfo();
}
/*
优点:
1 可以免去客户端直接创建特定对象的责任，而仅仅"消费"产品
2 客户端无须知道所创建对象的具体类名，就可以创建对象
缺点:
1 工厂类集中了所有特定对象的创建逻辑，一旦不能正常工作，整个系统都要受到影响
2 使用了简单工厂模式将会增加系统中类的个数，在一定程度上增加了系统的复杂度和理解难度
3 系统扩展困难， 一旦添加新产品就不得不修改工厂逻辑
4 简单工厂模式由于使用了静态工厂方法，造成工厂角色无法形成基于继承的等级结构

/*
适用环境:
1 工厂类负责创建的对象比较少：
2 客户端只知道传入工厂类的参数，对于如何创建对象不关心
*/