#include<iostream>

using namespace std;

class Box {
public:
    Box(double l = 2.0, double b = 2.0, double h = 2.0) {
        cout << "constructor called" << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume() {
        return length * breadth * height;
    }
    int compare(Box box) {
        return this->Volume() > box.Volume();
    }
private:
    double length;
    double breadth;
    double height;
};

int swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;

}

int main() {
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);
    Box* Box3 = new Box(15.0, 4.0, 3.0);

    if (Box3->compare(Box2)) {
        cout << "Box2 is smaller" << endl;
    }
    else {
        cout << "Box2 is equal or larger" << endl;
    }
    delete Box3;
    int a = 1, b = 2;
    swap(a, b);
    cout << a << "  " << b << endl;

    return 0;
}