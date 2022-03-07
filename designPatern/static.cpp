// static
// 静态成员变量
// 静态成员函数

#include<iostream>

using namespace std;

class Student {
public:
    Student(int id, int age);
    void show();
public:
    // 静态成员变量
    // 不占用对象内存, 在所有对象外开辟内存
    // 在 静态存储区
    static int total;

    // 静态成员函数
    // 不需要创建对象便可以调用
    // 静态成员函数只能访问静态成员

    static int getTotal();
private:
    int m_id;
    int m_age;
};

// 对静态成员变量类外初始化
// 必须初始化
// 格式必须: <对应的数据类型> <类名>::<变量名> = <数据>
int Student::total = 0;
// 构造函数, 创建对象时运行
Student::Student(int id, int age) :m_id(id), m_age(age) {
    total++;
}

void Student::show() {
    cout << m_id << "  " << m_age << endl;
}
// 静态成员函数的实现
int Student::getTotal() {
    return total;
}

int main() {
    cout << Student::total << endl;

    (new Student(00, 15))->show();
    Student* stu1 = new Student(01, 16);
    stu1->show();
    // 静态成员函数, 不需要创建对象就可以调用
    // 静态成员函数getTotal()只能调用静态成员变量total;
    cout << Student::getTotal() << endl;;
    return 0;
}

