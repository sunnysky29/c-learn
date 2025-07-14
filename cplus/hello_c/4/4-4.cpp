#include <iostream>
 
using namespace std;

int main()
{
    cout<<"请输入学生的语文、数学成绩(例如，82 96)：";
    // 定义变量保存输入的数据
	int nChs = 0;   // 语文成绩
	int nMath = 0;  // 数学成绩
    // 输入数据，并保存到变量
    cin>>nChs>>nMath;

    // 对变量进行逻辑判断评定等级
    // 首先判断两个分数是否都在60分以上，达到“合格”的标准
    // 这里用“&&”表示，(nChs >= 60)和(nMath >= 60)必须同时为true，
    // 整个表达式的值才为true，条件才会满足
	if((nChs >= 60)&&(nMath >= 60))
	{
		// 在“合格”的基础上，判断是否有一门的成绩在85以上，达到“优秀”的标准
        // 这里用“||”表示，只要(nChs >= 85)和(nMath >= 85)中有一个值为true，
        // 整个表达式的值就为true，条件满足
        if((nChs >= 85)||(nMath >= 85))
		{
			cout<<"优秀"<<endl;
		}
		else // 如果没有达到“优秀”的标准，那就是“合格”
		{
			cout<<"合格"<<endl;
		}
	}
	else // 如果没有达到“合格”标准，那就是“不合格”
	{
		cout<<"不合格"<<endl;
	}


    return 0;
}