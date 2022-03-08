/*
类似简单工厂, 但是每个产品对应一个工厂. 
如果有新的产品要生产, 则要创建一个新的工厂来生产该产品.
 */

#include<iostream>

using namespace std;

class Product {
public:
    virtual void show() const = 0;
};

class ProductA :public Product {
public:
    void show() const override {
        cout << " this is product A " << endl;
    }
};

class ProductB :public Product {
public:
    void show() const override {
        cout << " this is product B " << endl;
    }
};

class Factory {
public:
    virtual Product* create() const = 0;
};;

class FactoryA :public Factory {
public:
    Product* create() const override {
        return new ProductA;
    }
};

class FactoryB :public Factory {
public:
    Product* create() const override {
        return new ProductB;
    }
};

int main() {
    // 这是一种调用方法.
    Factory* factoryA = new FactoryA();
    // FactoryA* pA = new FactoryA();
    Product* pA = factoryA->create();
    // factoryA->create()->show();
    pA->show();

    // 这事另一种调用方法
    // 用这种!!!
    FactoryB* pB = new FactoryB();
    pB->create()->show();

    return 0;
}