// 原型模式
// 就是克隆, 拷贝
// 多用于创建复杂的或构造耗时的实例, 这时去复制一个已经存在的实例可使程序运行更高效
// 浅拷贝: 只拷贝基本类型数据, 而引用类型数据, 只是拷贝了一份引用地址
// 深拷贝: 在计算机中开辟了一块新的内存地址用于存放复制的对象


#include<iostream>

using namespace std;

class Prototype {
public:
    virtual Prototype* clone() = 0;
};

class ConcretePrototypeA :public Prototype {
private:
    int member;
public:
    ConcretePrototypeA() :member(0) {}
    ConcretePrototypeA(const ConcretePrototypeA& rhs) {
        member = rhs.member;
    }

    virtual ConcretePrototypeA* clone() {
        cout << "copy of self" << endl;
        return new ConcretePrototypeA(*this);
    }
};

int main() {
    ConcretePrototypeA* conPro = new ConcretePrototypeA();

    ConcretePrototypeA* conPro1 = conPro->clone();

    ConcretePrototypeA* conPro2 = conPro->clone();

    delete conPro;
    conPro = NULL;

    delete conPro1;
    conPro1 = NULL;

    delete conPro2;
    conPro2 = NULL;

    return 0;
}