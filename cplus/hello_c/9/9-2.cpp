#include <iostream>
#include <vector>

using namespace std;


int main()
{
	// 定义一个可以保存int类型数据的vector容器
    vector<int> vecSalary;
    // 接收用户输入并将数据保存到容器中
    int nInput = 0;

    do
    {
        cin>>nInput;  // 获取输入数据
        // 判断输入数据是否有效，如果是0，结束循环
        if ( 0 == nInput ) 
            break;
        // 通过push_back()函数将数据装入容器中
        vecSalary.push_back( nInput );
    } while( true );

    // 统计容器中所保存工资的总和
    int nTotal = 0;
    // 使用迭代器循环遍历容器中的数据
    // 将迭代器指向容器的起始位置
    for(vector<int>::iterator it = vecSalary.begin();      
        it != vecSalary.end();     // 判断是否到达容器的最后位置 
        ++it )     // 通过自增运算符将迭代器指向容器中的下一个元素
    {
        // 通过迭代器访问它所指向的数据元素
        nTotal += (*it);
    }

    cout<<"工资总数是："<<nTotal<<endl;
    
    return 0;
}