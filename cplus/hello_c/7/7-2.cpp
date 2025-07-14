#include <iostream>

using namespace std;

// 计算数组中所有数据元数 之和
// 其中，参数pArray 和nCount分别表示数组的首地址和数组元素的个数，
// 用于向函数传入一个数组，
// pSum指向用于保存结果数据的变量，用于从函数中传出计算结果
void SumArray(int* pArray, int nCount, int* pSum )
{
    // 参数有效性检查…

    int nRes = 0;  // 结果数据
    // 循环遍历整个数组，计算所有数据元素的和元数 的和
    for( int i = 0; i < nCount; ++i )
    {          
        // 通过pArray指针访问它所指向的函数外的nArray数组，
        // 读取其中的数据并累加到nRes中，实现向函数内传入数据
        nRes += *pArray; 
        pArray++;   // 指针加运算，访问数组中的下一个元素
    }
    // 通过pSum指针访问它所指向的函数外的nArraySum变量
    // 将结果数据写入这个变量，实现向函数外传出数据
    *pSum = nRes;
}

int main()
{
    // 保存结果数据的变量
    int nArraySum = 0;
    // 需要统计的数组
    int nArray[5] = { 1, 2, 3, 4, 5 };

    // 使用数组的首地址nArray传入数组，
    // 使用指向变量nArraySum的指针来接收计算结果
    SumArray(nArray, 5, &nArraySum);  
          
    // 运算结果已经保存在nArraySum中，直接输出运算结果
    cout<<"数组中所有数据之和是 :"<<nArraySum<<endl;

    return 0;
}
