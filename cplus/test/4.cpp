#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

int main() {

    int a = 238;
    int* ptr1= &a ;
    *ptr1 = 99;
    std::cout << "ptr1 = " << ptr1 << " ,value  "<< *ptr1 << "  , byte "<< sizeof(ptr1) << std::endl;  // 输出：ptr = 0x0


    double* ptr= (double*)&a ; // 写的话值是错的！！
    std::cout << "ptr = " << ptr << " ,value "<< *ptr << "  , byte "<< sizeof(ptr) << std::endl;  // 输出：ptr = 0x0

    char* buffer = new char[8];
    memset(buffer, 0, 8); // 置0 
    buffer[0] = 'H';
    std::cout << buffer << std::endl;  // 输出: Hi（后面是0，所以不会乱码）
    delete[] buffer;  // ✅ 重要：释放内存


    return 0;
}