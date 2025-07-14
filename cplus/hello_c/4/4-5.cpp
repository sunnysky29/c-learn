#include <iostream>
 
using namespace std;

int main()
{
    cout << "请输入两个整数:" << endl;
    int v1, v2;
    // 获取用户输入的数字
    cin >> v1 >> v2;
    
    if( v1 != v2 )     // 判断v1和v2是否相等，如果不相等，则继续判断大小
    {
        // 第二级if语句
        // 如果不相等，则继续判断v1是否大于v2
        if( v1 > v2 ) // 大于    
        {
            cout<<" v1 > v2 "<<endl;
        }    
        else  // 小于
        {
            cout<<" v1 < v2 "<<endl;
        }
    }
    else     // v1和v2相等
    {
        cout<<" v1 == v2 "<<endl;
    }

    return 0;
}