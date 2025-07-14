#include <iostream>
// 包含引入定义thread类的头文件
#include <thread>

// 使用thread所在的命名空间std
using namespace std;

// 定义需要线程执行的函数和函数对象
void ListenMusic()
{
	cout<<"听音乐"<<endl;
}

struct ReadBook
{
	void operator()()
	{
		cout<<"看书"<<endl;
	}
}; 

int main()
{
	// 使用函数对象创建线程对象readthread，并立即启动线程的执行
	ReadBook read;
	thread readthread(read);

	// 使用函数指针创建线程对象listenthread，并立即启动线程的执行
	thread listenthread(ListenMusic);

	// 处理其他业务逻辑

	// 调用join()函数，等待分支线程执行完毕
	readthread.join();
	listenthread.join();
	// 所有分支线程执行完毕，程序退出
	return 0;
}
