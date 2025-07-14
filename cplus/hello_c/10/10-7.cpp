// 引入需要的头文件
#include <vector>       
#include <algorithm>   // 为了使用copy_if()算法
#include <iostream>

using namespace std;

// 将考试成绩转换为学生等级的转换函数
char RateScore(int nScore)
{
	if(nScore >= 85) // 成绩高于等于85的是A等
	{
		return 'A';
	}
	else if(nScore >= 60)// 成绩高于等于60的是B等
	{
		return 'B';
	}
	else   // 成绩低于60的就是C等
	{
		return 'C';
	}
}

int main()
{
    // 保存原始的考试成绩的源容器
    vector<int> vecScore = {89,78,94,63,58};
    // 保存学生等级的目标容器	
    vector<char> vecGrade;
    // 根据源容器的数据多少调整目标容器的容量
    vecGrade.resize(vecScore.size());
    // 使用transform()算法将源容器中的学生成绩转换为学生等级并保存到目标容器
    // RateScore()函数负责具体的转换
	transform(vecScore.begin(),
		vecScore.end(),    // 参与转换的源容器范围 
		vecGrade.begin(), // 目标容器的起始位置
		RateScore);		  // 转换函数

    // 输出转换后的学生等级	
    for(char cGrade : vecGrade)
	{
		cout<<cGrade<<endl;
	}

    return 0;
}