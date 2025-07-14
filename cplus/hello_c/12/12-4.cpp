#include <iostream>
#include <fstream>
#include <memory>  // 包含引入shared_ptr所在的头文件


using namespace std;

//  使用shared_ptr代替普通指针向函数内传递数据
bool WriteToFile(shared_ptr<int> spScore,const unsigned int nCount)
{
	// 首先判断spScore是否有效
	if(false == spScore)
		return false; // 如果无效，直接返回fasle，表示操作失败
	// 打开输出文件
	ofstream out("data.txt");	// 打开输出文件
	if(!out.is_open())  		// 如果文件打开失败
		return false;

	// 用get()函数获得shared_ptr所指向内存资源的地址并保存到普通指针p
	// 这里指针p所指向的内容不能修改，所以我们在int之前加上const修饰
	const int* p = spScore.get();

	for(unsigned int i = 0; i < nCount; ++i)
	{
		out<<*p<<endl; 	// 通过普通指针直接读取内存位置上的数据并输出
		++p; 			// 将对普通指针进行加1运算，指向下一个数据所在的位置
	}
	out.close();

	return true;	
}

int main()
{
	const int N = 100;
	while(true)  	// 构造输入输出循环
	{
		// 输入数据个数为N

		// ...

		// 根据需要，动态地申请可以容纳N个int类型数据的内存资源，并用返回的内存地址
		// 创建spScore对象，也就是将这块内存资源交给spScore进行管理
		// 此时，只有变量spScore指向这块内存资源，其引用计数是1
		shared_ptr<int> spScore(new int[N]);
		// 获得指向这块内存资源的普通指针
		int* p = spScore.get();
		for(unsigned int i = 0;i < N; ++i)
		{
			cout<<"请输入第"<<i+1<<"个数据：";
			// 通过普通指针将输入的数据直接写入相应的内存位置
			cin>>*p;
			++p; // 对将普通指针进行加1运算，指向下一个内存位置
		}
		// 用spScore作为参数，向函数传递它所管理的内存资源
		// 此时，变量spScore和函数参数spScore都指向这块内存资源
		// 其引用计数增加1变为2
		WriteToFile(spScore,N);
		// WriteToFile()执行完毕，函数参数被释放
		// 此时只有变量spScore指向这块内存资源，其引用计数减1变为1
	}	// 一次while循环结束，变量spScore也被释放
	// 此时没有任何shared_ptr指向这块内存资源，其引用计数为0，资源自动被释放

	return 0;
}
