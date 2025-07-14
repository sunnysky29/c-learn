// Alarm.cpp 闹钟程序
#include <iostream>
// 为了调用GetLocalTime()和Sleep()函数，
// 首先引入其声明所在的<Windows.h>头文件
#include <Windows.h>

using namespace std;

// 自己定义的闹铃函数
void Alarm()
{
    // 输出十个’\a’字符，计算机响铃十次，代表闹钟响了
    for(int i = 0; i < 10; ++i)
	{
        cout<<'\a';
    }
}

int main()
{
    // 构造闹钟循环，不断获取当前时间并判断是否到了设定时间
    while(true)
    {
        SYSTEMTIME stLocal;
        // 直接调用GetLocalTime()函数获取系统时间
        GetLocalTime(&stLocal);
		
        // 判断是否到了设定时间8点
        if(8 == stLocal.wHour)
        {
            // 调用自己定义的函数，实现闹铃
            Alarm();
            // 已经闹铃，结束闹钟循环
            break;
        }

        // 如果尚未到达设定时间，调用Sleep()函数，
        // 程序执行暂停1秒钟，然后开始下一次循环
        Sleep(1000);
    }

    return 0;
}
