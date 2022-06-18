#include<bits/stdc++.h>

int main() {
    int a = 11;
    //定义一个引用，作为原本变量的别名
    int& b = a;

    std::cout << "a = " << a << "  " << "b = " << b << std::endl;
    std::cout << "&a = " << &a << "  " << "&b = " << &b << std::endl;
    //对引用的更改也能更改原来的变量
    b = 3;
    std::cout<< "b = " << b<<"  " << "a = "<<a<<std::endl;
    
    return 0;
}