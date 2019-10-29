/*
工厂方法模式
不再设计一个工厂来统一负责所有产品的创建，而是将具体对象的创建过程交给专门的工厂子类去完成，我们先定义一个抽线
的工厂类，再定义具体的工厂类来生成原型不同的具体对象，它们的实现在抽象工厂类中定义的方法。这种抽象
化的结果可以在不修复工厂类的情况下引进新的产品；如果出现了新的具体对象类型只需要创建一个具体的工厂类
就可以获得该新对象的实例。
*/
/*
工厂方法模式包含如下角色:
1 Product: 抽线产品
2 ConcreteProduct: 具体产品
3 Factory: 抽象工厂
4 ConcreteFactory: 具体工厂
*/
#include <iostream>


/**
 * 抽象日志产品
 */
class Log {
public:
    virtual void writeLog() = 0;
};


class FileLog : public Log {
public:
    FileLog() {};
    virtual void writeLog();
    ~FileLog() {};
};
void FileLog::writeLog() {
    std::cout << "我记录了FileLog" << std::endl;
}

class DatabaseLog : public Log{
public:
    DatabaseLog(){};
    virtual void writeLog();
    ~DatabaseLog(){};
};
void DatabaseLog::writeLog() {
    std::cout << "我记录了DatabaseLog" << std::endl;
}

/**
 * 抽象日志工厂
 */
class LogFactory {
public:
    LogFactory(){};
    virtual Log* createLog() = 0;
    ~LogFactory(){};
};

/**
 * 具体的文件日志工厂
 */
class FileLogFactory : LogFactory {
public:
    FileLogFactory(){};
    virtual Log* createLog();
    ~FileLogFactory(){};
};
Log* FileLogFactory::createLog() {
    return new FileLog();
}

/**
 * 具体的数据库日志工厂
 */
class DatabaseLogFactory {
public:
    DatabaseLogFactory(){};
    virtual Log* createLog() ;
    ~DatabaseLogFactory(){};
};
Log* DatabaseLogFactory::createLog() {
    return new DatabaseLog();
}

int main() {
    FileLogFactory a ;
    Log* b= a.createLog();
    b->writeLog();
    DatabaseLogFactory c ;
    Log* d = c.createLog();
    d->writeLog();
}

/*
工厂方法模式的优点
1 在工厂方法模式中，工厂方法用来创建客户所需要的产品，同时还向客服隐藏了哪种具体产品类将被实例化这一细节，
用户只需要关心所需产品对应的工厂，无须关心创建的细节，甚至无须知道具体产品类的类名
2 它能够使工厂可以自主确定创建何种产品对象，而如何创建这个对象的细节则完全封装在具体工厂内部。工厂
方法模式之所以又被称为多态工厂模式，是因为所有的具体工厂类都具有同一抽象父类.
3 系统扩展性好
*/

/*
模式扩展
1 使用多个工厂方法：在抽象工厂角色中可以定义多个工厂方法，从而使具体工厂角色实现这些不同的工厂方法，这些
方法可以包含不同的业务逻辑，以满足对不同的产品对象的需求
2 产品对象的重复使用：工厂对象将已经创建过的产品保存到一个集合（如数组、List等）中，然后根据客户对产品的请求，
对集合进行查询。如果有满足要求的产品对象，就直接将该产品返回客户端；如果集合中没有这样的产品对象，那么就创建一
个新的满足要求的产品对象，然后将这个对象在增加到集合中，再返回给客户端。
*/