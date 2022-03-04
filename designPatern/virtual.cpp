#include<iostream>

using namespace std;

class Base {
public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived :public Base {
public:
    void print() {
        cout << "Derived" << endl;
    }
    void test() {
        cout << "test" << endl;
    }
};

int main() {
    // 通过基类创建派生类对象,对象指针属于基类类别, 
    // 在这个对象中只能调用派生类继承自基类的函数或变量
    Base* p = new Derived();
    // p->test();
    // 👆这个函数将会报错

    Derived* q = new Derived();//派生类创建派生类对象
    Base* b = new Base();//正常创建基类对象
    p->print();
    q->print();
    b->print();
    p->Base::print();//派生类对象中调用基类函数.
    q->Base::print();

    delete p;
    delete q;
    delete b;
    return 0;
}