#include"Circle.h"
#include<iostream>

using namespace std;

int main() {
    Circle* circle = new Circle(4);;
    cout << "area=" << circle->Area() << endl;
    return 1;
}