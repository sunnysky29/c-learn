#include <mutex>  // 引入包含mutex所在的头文件
#include <queue>  // 引入包含queue容器所在的头文件
#include <string>
#include <thread>
#include <iostream>

using namespace std;

// 需要从线程函数传递出来的数据
class Food
{
public:
	Food(){} // 默认构造函数
	// 通过菜名构建Food对象
	Food(string strName) : m_strName(strName){}
	// 获取菜名
	string GetName() const
	{
		return m_strName;
	}
private:
	string m_strName; // 菜名
};

// 全局的互斥对象
mutex m;
// 全局的queue容器对象quFoods
// 线程函数会将炒好的菜通过push()方法放入quFoods容器，所以它表示服务员
queue<Food> quFoods;

// 线程函数，创建临界区访问共享资源quFoods
void Cook(string strName)
{
	// 炒菜
	// 这些不涉及共享资源的动作是可以放在临界区之外多个线程同时进行的
	Food food(strName);

	m.lock(); // 临界区开始
	// 对共享资源的操作
	quFoods.push(food);	// 将food对象添加到共享的容器中
	m.unlock(); 			// 临界区结束
}

int main()
{
	thread coWang(Cook,"回锅肉"); 	// 王厨师炒回锅肉
	thread coChen(Cook,"盐煎肉");	// 陈厨师炒盐煎肉
	// 等待厨师炒完菜
	coWang.join();
	coChen.join();
	// 输出结果
	cout<<"两位厨师炒出了"<<endl;
	// 输出quFoods容器中所有Food对象的名字
	// 这里只有主线程会执行，所以对共享资源的访问不需要放在临界区
	while(0 != quFoods.size() )
	{
		cout<<quFoods.front().GetName()<<endl;
		quFoods.pop(); // 从容器中弹出最先进入队列的Food对象
	}

	return 0;
}   