#include <iostream>
#include <vector>
// 包含引入定义thread类的头文件
#include <thread>

// 使用thread所在的命名空间std
using namespace std;

// 需要传递数据的线程函数
// 传值形式的参数strSong负责向线程函数内传入数据
// 传引用形式的参数vecEar负责向线程函数外传出数据
void ListenMusic(string strSong,vector<string>& vecEar)
{
	cout<<"我正在听"<<strSong<<endl; 	// 使用外部数据
	vecEar.push_back(strSong);  		// 将结果数据存入外部容器，以此实现传出数据传出
}

int main()
{
	// 准备需要传递的数据
	vector<string> vecEar; 				// 用于保存结果数据的容器
	string strSong = "歌唱祖国"; 		// 传入线程函数的数据
	// 在创建thread对象时传递数据
	// 第一个参数是线程函数指针，其后依次是线程函数所需要的参数
	thread listenthread(ListenMusic,strSong,ref(vecEar));

	// ...
	listenthread.join();

	// 输出结果数据
	for(string strName : vecEar)
		cout<<strName<<endl;

	return 0;
}


