#include <iostream>
#include <vector> // 引入map容器所在的头文件
#include <algorithm> // 引入算法所在的头文件

using namespace std;

// 利用函数定义我们对数据的处理方法，对于低于2000元的工资，就增加30%
// 函数只有一个参数，其类型是它将要处理的vector容器所保存数据的类型
// 因为要对容器中的数据进行修改，所以我们这里采用引用的参数形式
void AddSalary( int& nSalary )
{
    // 判断数据是否满足条件
    if( nSalary < 2000 )
        nSalary *= 1.3;    // 对数据进行处理
}

int main()
{ 
    // 构造容器，保存数据
    vector<int> vecSalary = {3500,1500,1000,2000,1200};
    
    // 使用for_each()算法，调用AddSalary()函数对容器中的数据进行处理
    for_each( vecSalary.begin(), // 开始位置
        vecSalary.end(), // 结束位置
        AddSalary );  // 处理方法

    // 调整工资后的数据
    for(int nSalary:vecSalary)
    {
        cout<<nSalary<<endl;
    }
    return 0;
}