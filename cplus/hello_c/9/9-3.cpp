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
    // 使用序列for循环语句简化容器的循环遍历 
    // 定义一个auto类型的循环变量n，表示这个容器数据序列中的每一个数据元素
    // 序列for循环语句的两个要素：循环变量和数据序列
    for(auto n : vecSalary )   
    {
        // 访问循环变量n，相当于访问数据序列中的每一个数据
        nTotal += n;
    }

    cout<<"工资总数是："<<nTotal<<endl;
    
    return 0;
}


