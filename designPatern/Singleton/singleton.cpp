/*
 单例模式
 保证一个类仅有一个实例, 并提供一个访问它的全局访问点.
 ---优点---
 只需要一个实例对象
 不用再new太多对象, 减少开销
 提高封装性
 为实例提供一个全局访问节点
 ---缺点---
 懒汉式, 以时间换空间
    在第一次使用时才初始化, 叫做延迟初始化.

 饿汉式, 以空间换时间
 */

 // 静态方法.

#include<iostream>

using namespace std;

// 懒汉式

class Singleton {
public:
    // c++11新特性
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void print() {
        cout << "this is a print function" << endl;
    }
private:
    static Singleton* instance; 

private:
    
    Singleton() {};
    ~Singleton() {};
    // 禁用拷贝构造和复制构造函数
    Singleton(const Singleton&) = delete;
    Singleton& operator =(const Singleton&) = delete;
};

// 饿汉式
// 使用静态变量的实现: 
//     可以解决 多线程/ 初始化顺序/ 资源释放 的问题

class EagerSgingleton {
private:
    static EagerSgingleton eInstance;
private:
    EagerSgingleton();
    ~EagerSgingleton();
    EagerSgingleton(const EagerSgingleton&);
    EagerSgingleton& operator=(const EagerSgingleton&);

public:
    // 不同方式
    // static EagerSgingleton* getInstance() {
    //     return &eInstance;
    // }

    static EagerSgingleton& getInstance() {
        return eInstance;
    }

};
EagerSgingleton EagerSgingleton::eInstance;

// 
int main() {
    //懒汉式的实体创建
    Singleton& instance1 = Singleton::getInstance();
    //饿汉式的实体创建.
    EagerSgingleton EagerSgingleton::eInstance;
    instance1.print();

    return 0;
}
