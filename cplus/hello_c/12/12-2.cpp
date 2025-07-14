#include <iostream>
#include <fstream>
using namespace std;
// 将指针所指向的内存位置上的数据写入文件
bool WriteToFile(const int* pScore,const unsigned int nCount)
{
	ofstream out("data.txt");	// 打开输出文件
	if(!out.is_open())  		// 如果文件打开失败
		return false;
	// 通过指针直接访问它所指向的内存位置上的数据
	for(unsigned int i = 0; i < nCount; ++i)
	{
		out<<*pScore<<endl;	// 直接读取内存位置上的数据并输出
		++pScore; 			// 指向下一个数据所在的位置
	}
	out.close();  			// 关闭文件

	return true;
}

int main()
{
	while(true)  				// 构造无限循环
	{
		unsigned int N = 0;  				// 数据个数
		cout<<"请输入数据个数：";
		cin>>N;						// 数据个数为0，循环结束
		if(0 == N)
			break;
		// 根据需要，动态地申请内存资源，得到的指针指向这块内存资源的首地址
		int* pScore = new int[N];

		for(unsigned int i = 0;i < N; ++i)
		{
			cout<<"请输入第"<<i+1<<"个数据：";
			// 通过指针将输入的数据直接写入相应的内存位置
			cin>>*pScore;

			++pScore; 		// 指向下一个内存位置
		}
		pScore -= N; 			// 调整指针指向，将其重新指向内存资源的首地址
		// 将指针指向的内存块上的数据写入文件
		WriteToFile(pScore,N);
	}

	return 0;
}
