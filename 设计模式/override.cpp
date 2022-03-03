#include<iostream>
#include<string>

using namespace std;

class Person {
public:
    virtual ~Person();
    virtual int Eat(int& num) = 0;
    virtual void Say();
    int Name() const;
};

class Student :public Person {
public:
    virtual ~Student();
    int Eat(int& num) {
        --num;
        return num;
    }
    void Say() {
        cout << "im full" << endl;
    }

};

class Teacher :public Person {
public:
    virtual ~Teacher();
    int Eat(int& num) {

    }
    void Say() override {
        
    }
};

int main() {
    int cakeNum;
    int stuNum = 10;
    cin >> cakeNum;
    Student* stu = new Student;
    for (int i = 0;i < 30;++i) {
        stu->Eat(cakeNum);
        stu->Say();
    }







}