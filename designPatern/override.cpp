//没不知道为啥没编译成功


#include<iostream>
#include<string>

#define MAXSTU 10

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
    int Eat(int& num) override {
        --num;
        return num;
    }
    void Say() override {
        cout << "im full" << endl;
    }

};

class Teacher :public Person {
public:
    virtual ~Teacher();
    int Eat(int& num) override {
        --num;
        return num;
    }
    void Say() override {

    }
    int Buy(int& num) {
        ++num;
        return num;
    }
};

int main() {
    int cakeNum;
    cin >> cakeNum;
    Student* stu = new Student();
    for (int i = 1;i <= MAXSTU;++i) {
        stu->Eat(cakeNum);
        stu->Say();
    }
    delete stu;

    Teacher* teacher = new Teacher();

    teacher->Eat(cakeNum);
    teacher->Eat(cakeNum);
    teacher->Eat(cakeNum);
    teacher->Eat(cakeNum);
    teacher->Buy(cakeNum);
    teacher->Buy(cakeNum);
    delete teacher;
    cout << cakeNum << endl;

    return 0;
}