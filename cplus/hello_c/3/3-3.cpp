// 引入定义输入/输出流对象的头文件
#include <iostream>
// 使用std名字空间命名空间
using namespace std;

int main()
{
	// 定义常变量PI
	const double PI = 3.14159;

    float fR = 19.82;  // 半径

	// 用常量PI计算面积
	float fArea = PI * fR * fR;
	// 用常量PI计算周长
	float fGirth = 2 * PI * fR;


    cout<<"圆的面积是："<<fArea<<" 周长是："<<fGirth<<endl;
    
    return 0;
}