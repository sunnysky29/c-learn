/*

-> 操作符

*/

#include <iostream>

class Entity { 
public:
    void print() {
        std::cout << "Hello" << std::endl;
    }
};

int main() {
    Entity e;
    Entity* ptr = &e;

    ptr->print();  // ✅ 正确：通过指针调用成员函数
    (*ptr).print();  // ✅ 正确：通过指针调用成员函数

    e.print();  // 也可以，但用的是对象本身

}