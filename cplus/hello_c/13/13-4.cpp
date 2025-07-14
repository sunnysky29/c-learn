#include <climits>  // 为了使用INT_MIN宏
#include <iostream>

using namespace std;
// ...
// 寻找数组中第二大的数
int find_second_max(const int* data,const int count)
{
	// 参数有效性检查
	if(nullptr == data || count <= 1)
		return 0;
	// 假定数组中的第一个数为最大的数
	int max = data[0];
	// 假定第二大数为最小的整数
	int sec_max = INT_MIN;

	// 从第二个位置开始循环遍历数组
	for (int i = 1; i < count; ++i)
	{
		// 如果当前数大于最大数
		if (data[i] > max)
		{
			// 原先的最大数成为第二大数
			sec_max = max;
			// 当前数成为最大数
			max = data[i];
		}
		else  // 当前数小于最大数
		{
			// 继续判断当前数是否大于第二大数
			if( data[i] > sec_max)
				sec_max = data[i];  // 如果大于，则当前数成为第二大数
		}
	}

	// 返回第二大数
	return sec_max;
}

int main()
{
	int arr[5] = {0,1,2,3,4};

	int second = find_second_max(arr,5);

	cout<<"数组中的第二大数字是："<<second<<endl;
	return 0;
}