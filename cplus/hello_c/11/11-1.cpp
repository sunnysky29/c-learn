#include <iostream>
#include <vector>

using namespace std;

// 定义函数指针类型RuleFunc，它可以指向返回值为bool类型
// 同时拥有一个int类型参数的函数
typedef bool (*RuleFunc)(int);

// 定义算法框架函数
int mycount_if(const vector<int>& v,	// 需要统计的容器
    RuleFunc is)			// 指向统计规则函数的函数指针
{
	int nTotal = 0;
	// 使用基于范围的序列for循环遍历容器中的数据
	for(int n:v)
	{
        // 通过函数指针调用规则函数
        // 判断当前数据是否符合统计规则
        if(is(n))
		{
			++nTotal;  	// 如果符合，则统计在内
		}
	}
	
    return nTotal;  		// 返回统计结果
}

// 统计规则函数，判断分数是否及格
bool IsPass(int n)
{
	return n >= 60;
}
// 统计规则函数，判断分数是否优秀
bool IsGood(int n)
{
	return n >= 85;
}

// 利用mycount_if()算法统计vector容器中的数据
int main()
{
    // 待统计的容器，添加初始数据
    vector<int> vecScore = {54,87,65,31,94};

    // 使用IsPass函数名作为mycount_if()算法的参数
    // 统计容器中的及格分数的个数
    int nPass = mycount_if(vecScore,IsPass);
    // 更换统计规则函数，统计容器中的优秀分数的个数
    int nGood = mycount_if(vecScore,IsGood);

    // 输出结果
    cout<<"及格人数"<<nPass<<endl;
    cout<<"优秀人数"<<nGood<<endl;

    return 0;
}
