// 2-2.cpp: 

#include <iostream>

using namespace std;

int main()
{
	// 用于保存用户输入数据的变量
	string strName;  // string类型的变量，用于保存用户输入的字符串
	int nAge = 0; // int类型的变量，用于保存用户输入的整数

	// 从cin对象中提取用户输入的字符串数据和整数数据，
	// 例如，在键盘输入"Liangqiao(空格)28(回车)"
	// cin会读取其中的"Liangqiao"和"28"这两个数据，
	// 并分别保存到strName和nAge这两个变量中
	cin>>strName>>nAge; 

    // 输出用户输入的数据
    cout<<"姓名:"<<strName<<" 年龄:"<<nAge<<endl;

	return 0;
}