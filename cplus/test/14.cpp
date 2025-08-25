/*
数组 

*/


#include <iostream>
using namespace std;


int main() {
    int example[5]={};
    example[0] = 2;
    example[4] = 4;

    int* ptr = example;
    *(ptr + 2) = 6;

    cout << "数组内容：" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "example[" << i << "] = " << example[i] << endl;
    }

    return 0;
}