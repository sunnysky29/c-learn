#include <iostream>

using namespace std;

// 除法函数
double Divide( int a, int b )
{
    if( 0 == b )
        throw "不能使用0作为除数";

    return (double)a/b;
}

int main()
{
    // 开始异常处理语句
    try
    {
        cout<<"请输入被除数与除数："<<endl;
        int a,b;   // 被除数与除数
        cin>>a>>b; // 接收用户输入
        // 进行除法运算，当b为0时会抛出异常
        double fRes = Divide( a, b );
        cout<<a<<"/"<<b<<" = "<<fRes<<endl;  // 输出结果
    }
    // 捕获try语句块中所抛出的字符串类型异常
    catch( char const* pMsg )
    {
        // 对异常进行处理
        // 这里仅仅是输出错误信息
        cout<<"程序运行发生异常："<<pMsg<<endl;
    }

    return 0;
}

