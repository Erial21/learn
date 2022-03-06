#include <iostream>    
using namespace std;

//定义抽象类  
class product1
{
public:
    virtual void show() = 0;
};

//定义具体类  
class product_A1 :public product1
{
public:
    void show() { cout << "product A1" << endl; }
};

class product_B1 :public product1
{
public:
    void show() { cout << "product B1" << endl; }
};

//定义抽象类  
class product2
{
public:
    virtual void show() = 0;
};

//定义具体类  
class product_A2 :public product2
{
public:
    void show() { cout << "product A2" << endl; }
};

class product_B2 :public product2
{
public:
    void show() { cout << "product B2" << endl; }
};
class Factory                //工厂
{
public:
    virtual product1* creat1() = 0;
    virtual product2* creat2() = 0;
};

class FactoryA                    //工厂A 可以有多个函数方法（产品）
{
public:
    product1* creat1() { return new product_A1(); }
    product2* creat2() { return new product_A2(); }
};

class FactoryB                   //工厂B 可以有多个函数方法（产品）
{
public:
    product1* creat1() { return new product_B1(); }
    product2* creat2() { return new product_B2(); }
};

int main()
{
    FactoryA* factoryA = new FactoryA();     //实例化--工厂对象A
    factoryA->creat1()->show();              //工厂A 调用函数（生产产品1）
    factoryA->creat2()->show();              //工厂A 调用函数（生产产品2）

    FactoryB* factoryB = new FactoryB();     //实例化--工厂对象B
    factoryB->creat1()->show();              //工厂B 调用函数（生产产品1）
    factoryB->creat2()->show();              //工厂B 调用函数（生产产品2）

    return 0;
}