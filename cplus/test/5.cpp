
/*
引用
*/
#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;

void increment(int& val){ //是一个引用，是某个int变量的别名
    val++;
    ++val;
}

void increment1(int* val){
    (*val)++;  //先 *val：获取指针指向的值
    // *val++;  // 实现不了效果！！

   
}

int main() {

    int a = 238;
    int& b = a;
    b = 98;
    log_(b);

    increment(b);
    log_(a);  // +2

    increment1(&a);
    log_(a);

    int aa= 5;
    int bb=8;
    int& ref =aa;
    ref = bb;  // 8,8

    increment(ref); // aa ++. ++ 
    log_(aa);
    log_(bb);

    int* ptr= &aa;
    *ptr = 1; // aa =1
    ptr = &bb;
    *ptr = -1;  //bb = -1
    increment1(ptr); // bb ++.
    log_(aa);
    log_(bb);

    return 0;
}