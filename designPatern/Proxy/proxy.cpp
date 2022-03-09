// 代理模式

#include<iostream>

using namespace std;

//定义接口, 对象类还是代理都继承于此.
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() {};
};
//定义实际方法的类
class RealSubject :public Subject {
public:
    void request() {
        cout << "This is RealSubject" << endl;
    }
};


//用于代理的类, 
class Proxy :public Subject {
private:
    RealSubject* realSubject;
public:
    void request() {
        //是否已经创建对象
        if (realSubject == NULL) {
            realSubject = new RealSubject();
        }
        //调用对象方法
        realSubject->request();
    }
};

int main() {
    Proxy* proxy = new Proxy();
    proxy->request();
    delete proxy;
    return 0;
}
