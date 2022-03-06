/*
 单例模式
 ---优点---
 只需要一个实例对象
 不用再new太多对象, 减少开销
 提高封装性
 为实例提供一个全局访问节点
 ---缺点---
 懒汉式, 以时间换空间
 饿汉式, 以空间换时间
 */

 // 静态方法.

#include<iostream>

using namespace std;

class Singleton {
public:
    // c++11新特性
    static Singleton* getInstance() {
        static Singleton* instance;
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
    Singleton(const Singleton&);
    Singleton& operator =(const Singleton&);
};

int main() {
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    if (instance1 == instance2) {
        cout << "instance1 = instance2" << endl;
    }

    instance1->print();

    return 0;
}
