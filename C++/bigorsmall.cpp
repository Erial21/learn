#include<iostream>

int main() {
    int i = 555;
    // if (*((char*)&i) == 0x12) {
    //     std::cout << "big" << std::endl;
    // }
    // else {
    //     std::cout << "small" << std::endl;
    // }
    std::cout << i << std::endl;
    std::cout << &i << std::endl;
    std::cout << (char*)&i << std::endl;
    std::cout << *((char*)&i) << std::endl;
    return 0;
}