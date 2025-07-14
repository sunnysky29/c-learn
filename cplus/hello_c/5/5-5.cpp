//  统计一个字符串中某个字符出现的次数
#include <iostream>
#include <cstring> // 引入字符查找函数strchr()所在的头文件

using namespace std;
 
// 用函数的递归调用实现统计字符在字符串中出现的次数
int CountChar(char* str,const char c)
{
    // 从字符串str的开始位置查找字符c
    char* pos = strchr(str,c);

    // 如果strchr()函数的返回值为nullptr，则意味着
    // 在字符串中再也找不到目标字符，递归的终止条件得到满足
    // 则结束函数的递归调用，直接返回本次的查找结果0 
    if(nullptr == pos)
	{
        return 0;
	}
		
    // 如果没有达到终止条件，则将本次查找结果1统计在内，
    // 并在新的开始位置pos + 1开始下一次查找，实现函数的递归调用
    return 1 + CountChar(pos + 1,c);
}

int main()
{
    // 字符串
    char str[] = "Thought is a seed";
    char c = 'h'; // 目标字符
    // 调用CountChar()函数进行统计
    int nCount = CountChar(str,c);
	// 输出结果
    cout<<"字符\'"<<c<<"\'在\""<<str<<"\"中出现了"
		<<nCount<<"次"<<endl;
		
    return 0;
}
