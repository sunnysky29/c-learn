#include <iostream>
#include <cmath>  // 引入fabs()函数所在的头文件

using namespace std;

int main()
{
    float a = 0.1;
    // 相等的误差范围	
    const float fEpsilon = 0.0001;
    // 判断两个浮点数之差的绝对值（用fabs()函数取得）是否在误差范围内
    // 如果在，则认为两个浮点数相等
	if(fabs(a*10 - 1.0) < fEpsilon)
	{
		cout<<"0.1*10等于1.0"<<endl;
	}
	else // 反之，则认为两个浮点数不相等
	{
		cout<<"0.1*10不等于1.0"<<endl;
	}

    return 0;
}