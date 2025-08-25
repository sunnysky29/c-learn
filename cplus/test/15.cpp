/*
字符串 

*/

#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;


int main() {
    const char* name = "sdtgbdsc";

    cout << "逐个字符显示：" << endl;
    const char* ptr = name;  // 从第一个字符开始
    while (*ptr != '\0') {   // 检查是否到达字符串结尾 \0
        log_(*ptr);
        ++ptr;
    }

    string n = string("WERSDF") + "54545";
    log_(n);

    

    return 0;
}
