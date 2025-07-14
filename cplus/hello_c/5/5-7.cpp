#include <assert.h>     // 引入断言头文件
using namespace std;

double Divide( int nDividend, int nDivisor )
{
    // 使用断言判断表示除数的参数nDivisor是否为0
    // 如果不为0，“0 != nDivisor”表达式的值为true
    // 断言通过，程序继续往下执行
    // 如果为0，则断言条件的值为false，断言会提示断言条件不成立
    assert( 0 != nDivisor );

    return (double)nDividend/nDivisor; 
}

int main()
{
    // 除数为0，Divide()函数被错误地调用
    double fRes = Divide( 3, 0 );

    return 0;
}
