#include <iostream>
using namespace std;

// 定义第一个Add()函数，使其可以计算两个int类型数据的和
int Add( int a, int b )
{
    cout<<"int Add( int a, int b )被调用！"<<endl;
    return a + b;
}
// 重载Add()函数，对其进行重新定义，
// 使其可以计算两个double类型数据的和
double Add( double a, double b )
{
    cout<<" double Add( double a, double b )被调用！"<<endl;
    return a + b;
}

int main()
{
    // 因为参数是整型数，其类型、个数
    // 与int Add( int a, int b )匹配
    // 所以int Add( int a, int b )被调用
    int nSum = Add(2,3);
    cout<<" 2 + 3 = "<<nSum<<endl;
    
    // 作为参数的小数会被表示成double类型，
    // 参数的类型、个数与double Add( double a, double b )匹配
    // 所以double Add( double a, double b )被调用
	double fSum = Add(2.5,10.3);
    cout<<" 2.5 + 10.3 = "<<fSum<<endl;

    return 0;
}
