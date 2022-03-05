#include<iostream>

using namespace std;

class Base {
public:
    virtual const string& color() = 0;
};

class Derived :public Base {
public:

    // 👇下面这段代码, 调用Base()无参构造函数, 也调用Derived()构造函数
    // 用构造函数初始化列表的方式为成员变量m_str设置默认值
    Derived() :Base(), m_str("black coat") {
        cout << "jjj" << endl;
    }


    const string& color() override {
        cout << m_str.data() << endl;
        return m_str;
    }
    string m_str;
};

int main() {
    Derived* d = new Derived();
    d->color();
    cout << d->m_str << endl;

    return 0;
}