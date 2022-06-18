
#include<bits/stdc++.h>

struct {
    unsigned int a : 1;
    unsigned int b : 1;
}status1;

struct Data {
    unsigned short max = std::numeric_limits<unsigned short>::max();
}status2;
namespace aa {
    void printstr(std::string str) {
        std::cout << str << std::endl;
    }
}


int main() {
    std::cout << sizeof(status1) << std::endl;
    std::cout << sizeof(status2) << std::endl;
    aa::printstr("Love you");
    return 0;
}
