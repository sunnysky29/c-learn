// 计算平方函数
int Power( int n )
{
    return n*n;
}
// 计算平方和函数
int PowerSum( int a, int b )
{
    return Power(a) + Power(b);
}

// 计算平方和的主函数
int main()
{
    // 调用求平方和函数
    int nRes = PowerSum(2,3);
    // ...

    return 0;
}