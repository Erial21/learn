//override 就是对基类的虚函数进行覆盖重新声明
//有助于代码的规范性, 整洁性

#include<iostream>

using namespace std;

class Base {
public:
    virtual void funcA(int arg) const {
        cout << "this is Base::funcA" << endl;
    }
};

class Derived :public Base {
public:
    virtual void funcA(int arg) const override {
        cout << "this is Derived::funcA" << endl;
    }
};

int main() {
    Derived* derived = new Derived();

    derived->funcA(99);
    return 0;
}

