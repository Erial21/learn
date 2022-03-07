#include<iostream>



class Singleton
{
public:
    //禁用拷贝构造和赋值构造函数
    Singleton(Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;
    ~Singleton() { std::cout << "destruct start" << std::endl; }
    //声明接口为静态函数，通过类名访问, 不用类外访问也可以
    static	Singleton& getInstance();
private:

    Singleton() { std::cout << "construct start" << std::endl; }

};

//类外实现
Singleton& Singleton::getInstance()
{
    //在函数内部定义的静态变量只会被定义初始化一次，
    // 也就是说第一次执行会初始化和定义
    static Singleton instance_;
    return instance_;//注意这里返回的时引用	
}

int main()
{
    Singleton& s1 = Singleton::getInstance();//所以必须定义引用来使用
    Singleton& s2 = Singleton::getInstance();
}
