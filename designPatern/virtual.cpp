// 一个问题, 有虚函数的情况下, 必须使用:
// Base* ptr=new Derived();
// 这种基类指针指向派生类对象吗?

// BaseClass : [Base Data]
// DerivedClass : [Base Data][Derived Data]
// 👆上面是基类和派生类中类似的数据结构, 
// Base* ptr=new Derived();形式, ptr只能访问[Base Data].

// 难道是为了表明 派生类中的函数是基类中声明的虚函数?
// https://juejin.cn/post/6844904054930292749 *
// https://www.cnblogs.com/clemente/p/13747491.html

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
    
    // 👇下面这条语句是函数隐藏的实现
    // 没有Base::print()语句, 默认调用派生类中的print()函数
    // 有Base::print()时调用基类中的print()函数
    q->Base::print();

    delete p;
    delete q;
    delete b;
    return 0; 
}