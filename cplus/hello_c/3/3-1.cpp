// 引入定义输入/输出流对象的头文件
#include <iostream>
// 使用std名字空间命名空间
using namespace std;
#include <chrono>
#include <thread>

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
	
// 	缓冲区是一个临时存储数据的内存区域，目的是提高 I/O 效率。
// 在 C++ 中，像 cout 这样的输出流默认使用缓冲区，不会立刻把内容显示出来，除非满足刷新条件（如遇到 endl、程序结束、缓冲区满等）。
// 它不是 bug，而是设计上的优化手段。 
	// cout << "Hello00" <<endl;   // 只换行，不刷新缓冲区
    // cout << "World \n";
    // abort();  // 强制终止程序，不会自动刷新缓冲区
	std::cout << "Hello";   // 没有 \n，也没有 endl
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << " World!";			
	

    return 0;
}