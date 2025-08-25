
/*

继承

*/

#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;


class Entity{
public:
    float x = 0.0f, y = 0.0f;  // C++11 默认成员初始化

    void move(float xa, float ya){
        x += xa;
        y += ya;
    }

};

class Player : public Entity{
public:
    const char* name;

    void print_name(){
        cout << name << endl;
    }
};

int main() {
    cout  << sizeof(Entity) << endl;
    cout  << sizeof(Player) << endl;

    Player player;
    player.name = "Alice";  // ✅ 赋值
    player.print_name();
    player.move(2,3);

    log_("!!!!!@@@");

    return 0;
}