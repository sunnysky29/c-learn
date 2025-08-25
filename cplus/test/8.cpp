
/*
静态
在 C++ 类中，static 关键字用于声明 不依赖于对象实例的成员。也就是说：
❝ 静态成员属于整个类，而不是某个对象。所有对象共享同一份静态成员。」 
*/
#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "--->" << message << endl;

struct entity
{
    // static 表示实例共享
    static int x,y;  //static  → 它们不属于某个对象，而是属于整个类。

    void print(){
        cout << x << ", " << y << endl;
    }
};

int entity::x=2;
int entity::y=189;

class Person {
    static int total;
    string name;
public:
    Person(string n) : name(n) { total++; }
    ~Person() { total--; }
    static int getTotal() { return total; }
};
int Person::total = 0;

void func(){
    static int i =0;
    // int i =0;

    i++;
    log_(i);
}

class Singleton{
public:
    static Singleton& get() {
        static Singleton instance;
        return instance;
    };

    void hello() { 
        log_("3wefdf !!");
    }
};


int main() {
    Singleton::get().hello();

    entity e;
    // e.x = 1;
    // e.y = 92;

    entity e1;
    // e1.x = 12;
    // e1.y = 435;

    e1.print();
    e.print();

    // 使用
    Person p1("Alice");
    Person p2("Bob");
    Person p3("Bosdb");
    cout << Person::getTotal() << endl;  // 输出 2

    func();
    func();
    func();
    func();

    return 0;
}

