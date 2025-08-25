/*
初始化

*/

#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;


class Entity{
private:
    string m_name;

public:
    Entity(){
        m_name = "Unknown";
    }

    Entity(const string& name){
        m_name = name;
        
    }

// const string& get_name() const
//  ↑↑↑↑↑↑↑↑↑↑↑↑  ↑↑↑↑↑↑↑↑↑↑↑↑↑↑
//      |               |
//      |               └─── 1. 表示这个成员函数不会修改对象状态
//      └──────────────────── 2. 表示返回的是一个不可修改的引用
    const string& get_name() const {
        // m_name = "Modified Inside Const Function";  // ❌ 错误：不能修改成员变量
        return m_name;
    }
};

int main() {
    Entity e0;
    cout << e0.get_name() << std::endl;

    Entity e1("WR3RFED");
    cout << e1.get_name() << std::endl;


    

    return 0;
}
