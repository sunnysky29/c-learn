#include <iostream>
#include <string>

using namespace std;

// 同一层级的两个同名函数因参数不同而形成重载
class Human
{
public:
	virtual void Talk()
	{
		cout<<"Ahaa"<<endl;
	}
	virtual void Talk(string msg)
	{
		cout<<msg<<endl;
	}
};

// 不同层级的两个同名且参数相同的函数形成重写
class Baby : public Human
{
public:
	virtual void Talk()
	{
		cout<<"Ma-Ma"<<endl;
	}
};

int main()
{
	Human MrChen;
	// 根据参数的不同来决定具体调用的重载函数，在编译时刻决定
	MrChen.Talk();   // 调用无参数的Talk()
	MrChen.Talk("Balabala"); // 调用以string为参数的Talk(string)

	Human* pBaby = new Baby();
	// 根据指针指向的实际对象的不同来决定具体调用的重写函数，在运行时刻决定
	pBaby->Talk(); // 调用Baby类的Talk()函数

	delete pBaby;
	pBaby = nullptr;

	return 0;
}