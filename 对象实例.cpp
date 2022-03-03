#include<iostream>

using namespace std;

class student {
public:
    string name;
    int age;
    bool sex;
};

int main() {
    student* stu1 = new student();
    stu1->name = "Erial";
    cout << stu1->name << endl;
    cin >> stu1->sex;
    if (stu1->sex) {
        switch (stu1->sex) {
        case 0:
            cout << "Female" << endl;
        case 1:
            cout << "Male" << endl;
        default:
            cout << "Error" << endl;
        }
    }
    else {
        cout << " Error " << endl;
    }
    delete stu1;
    return 0;
}