#include <iostream>

using namespace std;

// 获取两个数中的较大值
// T就是函数模板的类型参数
// 为了与标准库中的max()函数相区别，用mymax作函数名
// 为了防止数据被修改，使用const对参数和返回值进行修饰
template <typename T>
const T& mymax(const T& a, const T& b )
{
    return a > b ? a : b ;
}

int main()
{
	// 两个int类型数据
    int a = 4;
	int b = 5;
	cout<<a<<"和"<<b<<"之间较大的是"
			<<mymax<int>(a,b)<<endl;// 调用int版本的mymax()处理int类型数据
    // 两个string类型数据	
    string strA = "Good";
	string strB = "Afternoon";
    cout<<strA<<"和"<<strB<<"之间较大的是"
	   // 调用string版本的mymax()处理string类型数据
        <<mymax<string>(strA,strB)<<endl;
	
	return 0;
}