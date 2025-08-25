/*
多态

*/


#include <iostream>
#include <vector>
using namespace std;

// 基类
class Character {
public:
    virtual void say_hello() {
        cout << "Hello from a character!" << endl;
    }

    virtual ~Character() = default;  // 推荐：虚析构函数
};

// 派生类：玩家
class Player : public Character {
public:
    void say_hello() override {  // override 关键字确保正确重写
        cout << "Hey, I'm the player!" << endl;
    }
};

// 派生类：敌人
class Enemy : public Character {
public:
    void say_hello() override {
        cout << "Grrr! I'm an enemy!" << endl;
    }
};

int main() {
    Player player;
    Enemy enemy;

    Character* characters[] = {&player, &enemy};

    for (int i = 0; i < 2; ++i) {
        characters[i]->say_hello();  // ✅ 正确调用各自重写的函数！
    }

    return 0;
}