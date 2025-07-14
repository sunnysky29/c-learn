#include <iostream>

using namespace std;

// 胳膊
class Arm
{
public:
	// 胳膊提供的服务，拥抱
	void Hug()
	{
		cout<<"用手拥抱"<<endl;
	}
};
// 脚
class Leg
{
public:
	// 脚提供的服务，走路
	void Walk()
	{
		cout<<"用脚走路"<<endl;
	}
};
// 身体
class Body
{
public:
	// 身体提供的服务，都各自交由组成身体的各个部分去完成
	void Hug()
	{
		arm.Hug();
	}
	void Walk()
	{
		leg.Walk();
	}
private:
	// 组成身体的各个部分，因为它们与Body有着共同的生命周期，
	// 所以这里使用对象作为类的成员变量
	Arm arm;
	Leg leg;
};

int main()
{
	// 在创建Body对象的时候，同时也创建了组成它的Arm和Leg对象
	Body body;

	// 使用Body提供的服务，这些服务最终由组成Body的Arm和Leg去完成
	body.Hug();
	body.Walk();
	// 在Body对象销毁的同时，组成它的Arm和Leg对象也同时被销毁
	return 0;
}
