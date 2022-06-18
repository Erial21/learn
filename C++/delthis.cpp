#include<bits/stdc++.h>

class Del {
public:
    void del() {
        std::cout << "This instance has been deleted." << std::endl;
        delete this;
    }
    void pHello() {
        std::cout << "Hello World!" << std::endl;
    }
};

int main() {
    Del* d = new Del();
    d->pHello();
    delete d;
    d->pHello();
    return 0;

}