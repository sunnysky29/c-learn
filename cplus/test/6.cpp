
/*
类, 结构体

*/
#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;

class Player{
public:
    int x,y;
    int speed;

    void move( int xa, int ya){
        x  += xa * speed;
        y  += ya * speed;
        }

};

struct vec2  // 默认 public
{
    float x,y;

    void add(const vec2& other){
        x += other.x;
        y += other.y;

    }
};


int main() {

    Player player;
    player.move(1, -1);
 

    return 0;
}