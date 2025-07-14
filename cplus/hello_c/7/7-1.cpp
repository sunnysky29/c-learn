#include <iostream>

using namespace std;

int main()
{
    // 这是一个指针数组，其中保存的是各个字符串常量的首地址指针，其类型是const char*
    const char* arrMonth[]={"Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"};   
    // 定义一个指向指针的指针，
    // 因为要指向的指针是const char*类型，所以加上*后它自身的类型就是const char**
    // 这里数组的首地址arrMonth就是数组的第一个元素，
    // 也就是指向第一个字符串“Jan”的指针
    const char** pMonth = arrMonth;
    // 获取用户输入
    int   nIndex = 0; 
    cout<<"请输入月份对应的数字："<<endl;
    cin>>nIndex;
    // 对指针进行运算，使其指向相应的数组元素，
    // 也就是相应的字符串指针
    const char* pCurMonth = *(pMonth + ( nIndex - 1 ));
    cout<<"对应的月份是："<<pCurMonth<<endl;
    
    return 0;
}