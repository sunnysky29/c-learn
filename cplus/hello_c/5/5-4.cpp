#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // 根据指令的个数（argc），判断指令是否正确
    // 如果不正确，则提示正确的使用方法
    if(3 != argc)  // 通过argc得到指令个数
    {
        // 通过argv[0]得到程序的名字
        cout<<"用法: "<<argv[0]<<" num1 num2"<<endl;
        return -1; // 命令行指令不合法，返回一个错误值
	}

    // 如果指令正确，则通过argv访问命令行传递的数据
    // 通过atoi()函数，
    // 分别将argv[1]和argv[2]指向的字符串“3”和“5”转换为数字3和5
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    // 利用转换后的数据计算结果
    int res = a + b;
    // 输出结果
    // 这里，将命令行指令当作字符串来访问，直接输出
    cout<<argv[1]<<" + "<<argv[2]<<" = "<<res<<endl;
	
    return 0;
}