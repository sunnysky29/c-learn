// 引入定义输入/输出流对象的头文件
#include <iostream>
// 使用std名字空间命名空间
using namespace std;

int main()
{
	// 通过nWeight写入数据
	// 将“60”这个体重数据保存到内存
	int nWeight = 60; 
	// 通过nWeight读取数据
	// 将nWeight变量代表的体重数据“60”显示到屏幕
	cout<<"体重："<<nWeight<<endl; 
	
	// 通过变量名将体重数据修改为65
	nWeight = 65;
	// 输出修改后的体重数据
	cout<<"修改后的体重："<<nWeight<<endl;

    return 0;
}