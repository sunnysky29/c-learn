#include <iostream>

using namespace std;
// “上车买票”演示程序
// 定义Human类，这个类有一个接口函数BuyTicket()表示买票的动作
class Human
{
	// Human类的行为
public:
	// 买票接口函数
	void BuyTicket()
	{
		cout<<"人买票。"<<endl;
	}
};

// 从“人”派生两个类，分别表示老师和学生
class Teacher : public Human
{
public:
	// 对基类提供的接口函数重新定义，适应派生类的具体情况
	void BuyTicket()
	{
		cout<<"老师投币买票。"<<endl;
	}
};

class Student : public Human
{
public:
	void BuyTicket()
	{
		cout<<"学生刷卡买票。"<<endl;
	}
};

// 在主函数中模拟上车买票的场景
int main()
{
	// 车上上来两个人，一个是老师，另一个是学生
	// 基类指针指向派生类对象
	Human* p1 = new Teacher();
	Human* p2 = new Student();

	// 上车的人请买票
	p1->BuyTicket(); // 第一个人是老师，投币买票
	p1->BuyTicket(); // 第二个人是学生，刷卡买票

	// 销毁对象
	delete p1;
	delete p2;
	p1 = p2 = nullptr;

	return 0;
}
