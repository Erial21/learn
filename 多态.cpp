#include<iostream>

using namespace std;

class A {
public:
    void foo() {
        cout << "1" << endl;
    }
    virtual void fun() {
        cout << "2" << endl;
    }
};

class B :public A {
public:
    void foo() {
        cout << "3" << endl;
    }
    void fun() {
        cout << "4" << endl;
    }
};

int main() {
    A a;
    B b;
    A* p = &a;
    p->foo();
    p->fun();
    p = &b;
    p->foo();
    p->fun();
    return 0;
}