#include <iostream>

using namespace std;

// 定义一个加法函数
// 将函数定义在被调用的位置之前，函数的声明和定义同时完成
int Add(int a, int b)
{
    int nRes = a + b;
	
	return nRes;
}

// 在主函数中调用加法函数
// 这时的main()主函数就是Add()函数的主调函数，Add()函数就是被调函数
int main()
{
    // 准备函数调用的实际参数
    int a = 1;
    int b = 2;
    // 以a和b作为实际参数调用Add()加法函数
    int nRes = Add(a, b);
    cout<<a<<" + "<<b<<" = "<<nRes<<endl;

    return 0;
}
