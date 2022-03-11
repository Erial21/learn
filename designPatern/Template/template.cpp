// 模板方法模型
// 数据库访问的封装

// 方式: 模板, 顾名思义, 对象的行为是有规划的, 只有少数几个对象
// 中的方法是重新由派生子类重新定义. 

#include<iostream>

using namespace std;

class RestaurantTemplate {
public:
    void Menu() {
        cout << "watch menu..." << endl;
    }
    virtual void Order() = 0;

    virtual void Eat() {
        cout << "eating..." << endl;
    }

    virtual void Cost() = 0;

    virtual void Leave() {
        cout << "Leaving..." << endl;
    }

    void process() {
        Menu();
        Order();
        Eat();
        Cost();
        Leave();
    }
};

class Ginsen :public RestaurantTemplate {
public:
    void Order()override {
        cout << "Order Ginsen" << endl;
    }
    void Cost()override {
        cout << "cost 5 yuan" << endl;
    }
};

class Lobster :public RestaurantTemplate {
public:
    void Order()override {
        cout << "Lobster" << endl;
    }
    void Cost()override {
        cout << "50 yuan" << endl;
    }
};

int main() {
    RestaurantTemplate* restaurantTemp = new Ginsen();
    restaurantTemp->process();
    return 0;
}
