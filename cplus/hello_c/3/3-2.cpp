// 引入定义输入/输出流对象的头文件
#include <iostream>
// 使用std名字空间命名空间
using namespace std;

int main()
{
	// 将3.14159定义成宏PI
	#define PI 3.14159

	float fR = 19.82;  // 半径
	// 用PI计算面积
	float fArea = PI * fR * fR;
	// 用PI计算周长
	float fGirth = 2 * PI * fR;

    cout<<"圆的半径为："<<fR <<endl;
    cout<<"圆的面积是："<<fArea<<" 周长是："<<fGirth<<endl;
    cout<<"pi："<<PI <<endl;

    
    return 0;
}