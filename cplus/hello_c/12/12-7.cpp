#include <iostream>
#include <thread>  	// 包含引入线程相关的头文件
#include <chrono>		// 引入包含时间相关的头文件

using namespace std;
using namespace std::chrono;  		// 使用时间相关的命名空间

int main()
{
	// 构造一个世界末日的固定时间点：2012年 12月21日零时
	tm timeinfo = tm();
	timeinfo.tm_year = 112;   	// 年: 2012 = 1900 + 112
	timeinfo.tm_mon = 11;      	// 月：12 = 1 + 11 
	timeinfo.tm_mday = 21;     	// 21日
	time_t tt = mktime(&timeinfo);
	// 利用time_t类型的变量tt
	// 创建一个表示世界末日固定时间点的time_point对象tp
	system_clock::time_point tp = system_clock::from_time_t (tt);

	// 当前线程一直瞌睡到tp表示的2012年12月21日0时
	this_thread::sleep_until(tp); 

	// 世界末日到了，程序继续恢复执行，响铃10次发出警报
	for(int i = 0; i < 10; ++i)
	{
		cout<<'\a';  // 输出一个计算机响铃
		// 当前线程瞌睡一秒钟，然后继续恢复执行下一次循环
		this_thread::sleep_for(seconds(1));
	}

	return 0;
}