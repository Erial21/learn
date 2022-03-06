#include<iostream>

using namespace std;

enum SHOES_TYPE {
    Nike,
    Adidas,
    Anta
};
//鞋子抽象类, 类方法, 打印, 等于生产的产品
class Shoes {
public:
    virtual ~Shoes() {}
    virtual void show() = 0;
};

//具象品牌类, 继承鞋子抽象类, 对抽象类中定义的虚函数进行修改打印符合需求的句子
class Nikeshoes :public Shoes {
public:
    void show() {
        cout << "im Nike" << endl;
    }
};

class Adidasshoes :public Shoes {
public:
    void show() {
        cout << "im Adidas" << endl;
    }
};

class Antashoes :public Shoes {
public:
    void show() {
        cout << "im Anta" << endl;
    }
};

//工厂类
class ShoesFactory {
public:
    Shoes* creatShoes(SHOES_TYPE type) {
        switch (type) {
        //根据类别创建对象.
        case Nike:
            return new Nikeshoes;
        case Adidas:
            return new Adidasshoes;
        case Anta:
            return new Antashoes;
        default:
            return nullptr;
        }
    }
};

int main() {
    //创建工厂对象
    ShoesFactory* factory = new ShoesFactory();
    //在工厂中, 创建相应品牌的对象
    Shoes* nike = factory->creatShoes(Nike);
    if (nike) {
        //调用此品牌对象中的修改的函数
        nike->show();
        //释放资源
        delete nike;
    }

    Shoes* anta = factory->creatShoes(Anta);
    if (anta) {
        anta->show();
        delete anta;
    }

    Shoes* adidas = factory->creatShoes(Adidas);
    if (Adidas) {
        adidas->show();
        delete adidas;
    }
    delete factory;
    return 0;
}