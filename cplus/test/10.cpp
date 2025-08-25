
/*

构造函数/ 析构

*/

#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;


class Entity{
public:
    float x,y;
    Entity(){ //构造
        x= 30.01f;
        y= 0.0f;
        std::cout << "[Constructor] Default called!" << std::endl;

    }

    Entity(float xx, float yy){ // 有参构造函数
        x= xx;
        y =yy;
        std::cout << "[Constructor] Parameterized called! xx=" << xx << ", yy=" << yy << std::endl;

    }

    ~Entity(){
        cout  << "destroyed !!" << endl;
    }

    void print(){
        cout << x << ", " << y << endl;
    }

    // void init(){
    //     x= 0.0f;
    //     y= 0.0f;
    // }
};

int main() {

    Entity e1;
    Entity e(1.1f ,2.0f);

    // e.init();

    log_(e.x);
    e.print();

    log_("!!!!!@@@");

    return 0;
}