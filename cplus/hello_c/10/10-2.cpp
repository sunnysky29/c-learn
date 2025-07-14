#include <iostream>
#include <vector> // 引入map容器所在的头文件
#include <algorithm> // 引入算法所在的头文件

using namespace std;

// 使用函数表达查找规则：查找及格分数
// 如果分数大于等于60，就返回true，表示及格，否则返回false
bool ispass( int n )
{
    // 判断传递的数据是否符合条件
    // 如果符合条件，返回true，否则返回false
    return n >= 60 ? true : false; 
}

int main()
{ 
    // 定义保存成绩的容器
    vector<int> vecScores = {97,56,82,81,59,60};
    // 定义查找的起始位置
    auto it = vecScores.begin();
    // 利用循环，逐个查找容器中符合条件的数据
    do
    {
        // 在容器中查找符合条件的数据元素，
        // 其中ispass表达了查找规则
        it = find_if(it, vecScores.end(), ispass );
        if ( vecScores.end() != it ) // 判断是否找到符合条件的数据
        {
            // 输出查找到的符合条件的数据
            cout<<"找到及格分数："<<(*it)<<endl;
            // 将迭代器指向下一个位置，从新的位置开始下一次查找
            ++it;
        }
        else
        {
            // 如果没有找到，就退出循环
            break;
        }
    } while( true );  

    return 0;
}