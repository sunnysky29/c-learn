// shared_ptr定义在头文件<memory>中
#include <memory>
#include <iostream>

using namespace std;

int main()
{
	shared_ptr<int> spFirst( new int );
	// 这时，只有spFirst这个指针指向这块int类型的内存资源
	// 所以这时它的引用计数是1
	cout<<"当前引用计数: "<<spFirst.use_count()<<endl;
	{
		// 创建另一个shared_ptr，并用spFirst对其进行赋值
		// 让它们指向同一块内存资源
		shared_ptr<int> spCopy = spFirst;
		// 因为spFirst和spCopy都指向这一块内存资源
		// 所以这一资源的引用计数增加为2
		cout<<"当前引用计数: "<<spFirst.use_count()<<endl;
	}
	// 当超出spCopy的作用域，spCopy结束其生命周期
	// 这块内存资源的引用计数减1，重新变为1
	cout<<"当前引用计数: "<<spFirst.use_count()<<endl;

	// 当程序最终结束执行并返回，spFirst指针也结束其生命周期后
	// 从此没有任何指针指向此内存资源，引用计数变为0，内存资源自动得到释放
	return 0;
}
