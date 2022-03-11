// 建造者模式

#include<iostream>
#include<string>

using namespace std;

// 具体产品类
class Bike {
private:
    string frame;
    string seat;
public:
    string getFrame() {
        return frame;
    }
    void setFrame(string frame) {
        this->frame = frame;
    }
    string getSeat() {
        return seat;
    }
    void setSeat(string seat) {
        this->seat = seat;
    }
};

// 抽象Builder类
class Builder {
protected:
    Bike* mBike = new Bike();
public:
    virtual void buildFrame() = 0;
    virtual void buildSeat() = 0;
    virtual Bike* createBike() = 0;
};

//具体的Builder类
class MobikeBuilder :public Builder {
public:
    void buildFrame() override {
        mBike->setFrame("铝合金车架");
    }
    void buildSeat() override {
        mBike->setSeat("真皮车座");
    }
    Bike* createBike() override {
        return mBike;
    }
};

class OfoBuilder :public Builder {
public:
    void buildFrame() override {
        mBike->setFrame("碳纤维车架");
    }
    void buildSeat() override {
        mBike->setSeat("橡胶车座");
    }
    Bike* createBike() override {
        return mBike;
    }
};

// 构造一个使用Builder接口的对象
class Director {
private:
    Builder* mBuilder;
public:
    Director(Builder* builder) {
        mBuilder = builder;
    }
    Bike* construct() {
        mBuilder->buildFrame();
        mBuilder->buildSeat();
        return mBuilder->createBike();
    }
};

int main() {
    MobikeBuilder* moBuilder = new MobikeBuilder();
    OfoBuilder* ofoBuilder = new OfoBuilder();
    Director* director = new Director(moBuilder);
    Bike* bike = director->construct();
    cout << bike->getFrame() << endl;
    cout << bike->getSeat() << endl;
    delete director;
    Director* oDirector = new Director(ofoBuilder);
    Bike* oBike = oDirector->construct();
    cout << oBike->getFrame() << endl;
    cout << oBike->getSeat() << endl;

}