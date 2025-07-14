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

    // 定义索引值变量，用于访问容器中的数据
    vector<int>::size_type nIndex = 0;
    // 循环遍历vector容器
    for( auto it = vecSalary.begin(); 
      it != vecSalary.end(); ++it, ++nIndex )
    {
        // 通过迭代器读取容器中的数据
        cout<<"当前工资是："<<*it<<endl;
        // 通过at()函数修改容器中元素的值
        vecSalary.at( nIndex ) += 1000;     // 涨工资啦！每个人加1000元！
        cout<<"涨工资之后是："<<*it<<endl;
    }

    return 0;
}


