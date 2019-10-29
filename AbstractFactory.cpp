/*
工厂模式中具体工厂负责生产具体的产品，每一个具体工场对应一种具体产品，工厂方法具有唯一性，一般情况下
一个具体工厂中只有一个工厂方法或者一组重载的工厂方法。但是有时候我们需要一个工厂可以提供多个产品对象
，而不是单一的产品对象。

先引入两个概念：
1 产品等级结构：产品等级结构即产品的继承结构，如一个抽象类是电视机，其子类有海尔电视机，海信电视机
TCL电视机，则抽象电视机与具体品牌的电视机之间构成了一个产品等级结构，抽象电视机是父类，而具体品牌的电视机
是其子类。
2 产品族：在抽象工厂模式中，产品族是指由同一个工厂生产的，位于不同产品等级结构中的一组产品，如海尔电器
工厂生产的海尔电视机，海尔电冰箱，海尔电视机位于电视机产品等级结构中，海尔电冰箱位于电冰箱产品等级结构中
*/
/*
当系统所提供的工厂所需生产的具体产品并不是一个简单的对象，而是多个位于不同产品等级结构中属于不同类型
的具体产品时需要使用抽象工厂模式。
抽象工厂模式是所有形式的工厂模式中最为抽象和最具一般性的一种形态
抽象工厂模式与工厂方法模式最大的区别在于，工厂方法模式针对的是一个产品等级结构，而抽象工厂模式则需要面对
多个产品等级结构。当一个工厂等级结构可以创建出分属不同产品等级结构的一个产品族中的所有对象时，抽象
工厂模式比工厂方法模式更为简单，有效率。
*/
/*
模式定义
抽象工厂模式(Abstract Factory Pattern)：提供一个创建一系列相关或相互依赖对象的接口，
而无须指定它们具体的类。抽象工厂模式又称为Kit模式，属于对象创建型模式。
*/
/*
模式结构
1 AbstractFactory: 抽象工厂
2 ConcreteFactory: 具体工厂
3 AbstractProduct: 抽象产品
4 Product:         具体产品
*/
/*
优点：
可以将一组具有同一主题的单独的工厂封装起来。在正常使用中，客户端程序需要创建抽象工厂的具体实现
然后使用抽象工厂作为接口来创建这一主题的具体对象。客户端程序在不需要知道（或关心）它从这些内部
的工厂方法中获得对象的具体类型，因为客户端程序仅使用这些对象的通用接口。抽象工厂模式将一组对象的实现
细节与它们的一般使用分离开来
*/

/*
例子:
有个项目原来是依赖于access数据库，现在要用sqlserver，怎么更改呢(解耦)？
*/

#include <iostream>
class IDepartment {
public:
    virtual void Insert(Department department) = 0;
    virtual Department GetDepartment(int id) = 0;
};

//SqlserverDepartment 类，用于访问SQL Server的Department
class SqlserverDepartment : IDepartment {
public:
    virtual void Insert(Department department);
    virtual Department GetDepartment(int id);
};
void SqlserverDepartment::Insert(Department department) {
    std::cout << "在SQL Server中给Department表增加一条记录" << std::endl;
}
Department SqlserverDepartment::GetDepartment(ind id) {
    std::cout << "在SQL Server中给Department表获取一条记录" << std::endl;
}

class AccessDepartment : IDepartment {
public:
    virtual void Insert(Department department);
    virtual Department GetDepartment(int id);
};
void AccessDepartment::Insert(Department department) {
    std::cout << "在Access中给Department表增加一条记录" << std::endl;
}
Department AccessDepartment::GetDepartment(int id) {
    std::cout << "在Access中给Department表增加一条记录" << std::endl;
}

class IUser {
public:
    virtual Insert(User user) = 0;
    virtual GetUser(int id) = 0;
}

class SqlserverUser : IUser {
public:
    virtual void Insert(User user);
    virtual User GetUser(int id);
};
void SqlserverUser::Insert(User user) {
    std::cout << "在SQL Server中给User表增加了一条记录" << std::endl;
}
User SqlserverUser::GetUser(int id) {
    std::cout << "在SQL Server中给User表获取一条记录" << std::endl;
}

class AccessUser : IUser{
public:
    virtual void Insert(User user);
    virtual User GetUser(int id);
};
void AccessUser::Insert(User user) {
    std::cout << "在access中给User表增加一条记录" << std::endl;
}
User AccessUser::GetUser(intid) {
    std::cout << "在access中给User表获取一条记录" << std::endl;
}
//抽象工厂
class factory {
public:
    virtual IUser CreateUser() = 0;
    virtual IDepartment CreateDepartment() = 0;
};



//Sqlserver具体工厂，
class SqlserverFactory : factory {
public:
    virtual IUser CreateUser() {
        return new SqlserverUser();
    }
    virtual IDepartment CreateDepartment() {
        return new SqlserverDepartment();
    }
};
//AccessFactory具体工厂
class AccessFactory : factory {
public:
    virtual IUser CreateUser() {
        return new AccessUser();
    }
    virtual IDepartment CreateDepartment() {
        return new AccessDepartment();
    }
};
