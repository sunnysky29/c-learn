#include <iostream>

using namespace std;

int main()
{
    int nAge = 0;
	cout<<"请输入你的年龄：";
    // 用户输入年龄	
    cin>>nAge;
    // 用关系操作符“>=”判断输入的年龄是否大于等于18
    // 判断是否成年人
	if(nAge >= 18)
	{
		// nAge的值大于等于18
        cout<<"欢迎来到红树林网吧"<<endl;
	}
	else   // nAge的值小于18
	{
		cout<<"很抱歉，未成年人不能进入"<<endl;
	}

    return 0;
}