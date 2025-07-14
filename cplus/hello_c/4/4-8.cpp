// 每月收支统计程序
#include <iostream>
using namespace std;

int main()
{
    // 输出用户提示
    cout << "======每月收支统计程序======" << endl; 
    cout << "请输入你本月的收入(正数)和支出(负数)，0表示输入结束。" << endl;

    // 收支数目 
    int nInput = 0;
    // 收支总数
    int nTotal = 0;
    // 第一次循环，无条件执行循环动作
    // 其后的循环，要在循环条件满足的情况下才能执行
    do
    {
        // 接受用户输入的收支数目并保存到nInput 
        cin>>nInput;
        // 对收支进行统计，将其加和到收支总数nTotal
        nTotal += nInput;
    } while( 0 != nInput ); // 对循环条件进行判断，以决定是否进行下一次循环

    // 输出统计结果
    cout << "你本月的结余是：" << nTotal << endl;
 
    return 0;
}