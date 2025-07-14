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

    return 0;
}