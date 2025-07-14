// 引入需要的头文件
#include <vector>       
#include <algorithm>   // 为了使用copy_if()算法
#include <iostream>

using namespace std;

// 复制规则函数
bool isgood(int n)
{
	// 优秀的成绩（大于等于85）才会返回true，才会被复制
    return n >= 85 ? true : false;
}

int main()
{
	// 保存所有成绩的源容器
    vector<int> vecAll = {64,89,91,68,99,75};
    // 用于保存筛选出来的优秀学生成绩的目标容器
    vector<int> vecGood;  
	// 为目标容器预留足够的空间
    vecGood.resize(vecAll.size());
	 	
    // 使用copy_if()算法将源容器中的优秀成绩复制到目标容器中
    // copy_if()算法的返回值，是目标容器中被复制数据的末尾位置
    auto itend = copy_if(vecAll.begin(),vecAll.end(), // 复制的范围
		 	        vecGood.begin(),	// 目标容器的起始位置
		 	        isgood);		// 复制规则
	 
    cout<<"筛选出来的优秀成绩："<<endl; 
    // 使用for_each()算法，输出复制到目标容器中的数据
    for_each(vecGood.begin(),
        itend,  // 使用copy_if()算法的返回值作为结束位置
        [](int a){  // 使用Lambda表达式输出数据
            cout<<a<<endl;
        });
	 	
    return 0;
}