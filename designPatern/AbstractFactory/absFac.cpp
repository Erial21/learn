/*
提供一个接口，让该接口负责创建一系列”相关或者相互依赖的对象“，
无需指定它们具体的类。 ——《设计模式》GoF

设计模式 57页
 */
 /*
 本例中, 颜色是抽象的, 什么颜色的产品是具象的, 
 从抽象的颜色工厂去生产具象的产品.

 用户仅通过AbsFactory接口创建窗口组件,
 他们并不需要知道些类实现了什么风格的什么产品. 
 用户仅与抽象类定义的接口交互, 不使用具体类的接口.
  */
#include<iostream>

using namespace std;


// 一个鞋类的抽象产品
class Shoe {
public:
    virtual ~Shoe() {};
    virtual string usefulFuncA() const = 0;
};

// 两个鞋类的具体产品类
class redShoe :public Shoe {
public:
    string usefulFuncA() const override {
        return "red shoe";
    }
};

class blackShoe :public Shoe {
public:
    string usefulFuncA() const override {
        return "black shoe";
    }
};


class Hat {
public:
    virtual ~Hat() {};
    virtual string usefulFuncB() const = 0;

    virtual string usefulFuncBb(const Shoe& collaborator) const = 0;
};

class redHat :public Hat {
    string usefulFuncB() const override {
        return "red hat";
    }
    string usefulFuncBb(const Shoe& collaborator)const override {
        const string result = collaborator.usefulFuncA();
        return "result of red hat collaborating with(" + result + ")";
    }
};

class blackHat :public Hat {
    string usefulFuncB() const override {
        return "black hat";
    }
    string usefulFuncBb(const Shoe& collaborator)const override {
        const string result = collaborator.usefulFuncA();
        return "result of black hat collaborating with(" + result + ")";
    }
};

// 抽象工厂, 调用创建接口
class AbsFactory {
public:
    // 创建对象的接口
    virtual Shoe* createShoe() const = 0;
    virtual Hat* createHat() const = 0;
};

// 生产具体产品的抽象工厂 红色
class redThing :public AbsFactory {
public:
    Shoe* createShoe() const override {
        return new redShoe();
    }
    Hat* createHat() const override {
        return new redHat();
    }
};

// 生产具体产品的抽象工厂 黑色
class blackThing :public AbsFactory {
public:
    Shoe* createShoe()const override {
        return new blackShoe();
    }
    Hat* createHat() const override {
        return new blackHat();
    }
};



void clientCode(const AbsFactory& factory) {
    const Shoe* shoe = factory.createShoe();
    const Hat* hat = factory.createHat();
    cout << hat->usefulFuncB() << endl;
    cout << hat->usefulFuncBb(*shoe) << endl;
    delete shoe;
    delete hat;
}

int main() {
    cout << "client: testing client code with the first factory type" << endl;
    redThing* redfac = new redThing();
    clientCode(*redfac);
    delete redfac;

    cout << endl;

    cout << "client: testing the same client code with the seconod factory type" << endl;
    blackThing* blackfac = new blackThing();
    clientCode(*blackfac);
    delete blackfac;

    return 0;
}

