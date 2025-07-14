#include <vector>	 // 为了使用vector容器	
#include <algorithm>  // 为了使用remove()和replace_if()算法
#include <iostream>

using namespace std;

// 判断分数是否不及格（小于60）的函数
bool isfail(int nScore)
{
    return nScore < 60 ? true : false;
}

int main()
{
	// 待处理的成绩数据
    vector<int> vecScores = {54,-1,92,49,5,67};
		
    // 从容器中删除缺考成绩-1
    // remove()算法实质上是将待删除的数据移动到容器末尾部分来实现删除
    // 所以我们这里要用itend保存remove()算法返回的vecScores容器新的末尾位置
    // 这样，从vecScores.begin()到itend界定了容器中的有效数据的范围
    // 而在itend之后vecScores.end()之前的是被删除的无效数据
	auto itend = remove(vecScores.begin(),
        vecScores.end(),
        -1);  // 需要删除的元素
	 
	replace_if(vecScores.begin(),// 开始位置
        itend, // vecScores新的结束位置，也可以使用end()得到此位置
		isfail, // 判断数据是否符合替换条件
		60);     // 替换后的数据

	// 输出处理后的数据 
    for(auto it = vecScores.begin();it != itend; ++it)
	{
		cout<<*it<<endl;
	}

	return 0;
}