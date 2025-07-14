#include <thread>
#include <future>  // 包含引入future所在的头文件
#include <string>
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

// 线程函数
// 根据菜名创建Food对象，并通过promise对象返回结果数据
void Cook(const string strName,promise<Food>& prom)
{
	// 做菜
	Food food(strName);
	// 将创建完成的food对象放到promise传递出去
	prom.set_value(food);
}

int main()
{ 
	// 用于存放结果数据的promise对象
	promise<Food> prom;
	// 获得promise所关联的future对象
	future<Food> fu = prom.get_future();

	// 创建分支线程执行Cook()函数
	// 同时将菜名和用于存放结果数据的promise对象传递给Cook()函数
	// ref()函数用于获取promise对象的引用
	thread t(Cook,"回锅肉",ref(prom));

	// 主线程在此等待分支线程完成Food对象的创建，一旦完成，立即获取完成的Food对象
	Food food = fu.get();
	// 上菜
	cout<<"客官，你点的"<<food.GetName()<<"来了，请慢用！"<<endl;
	t.join(); // 等待分支线程最终完成

	return 0;
}
