// 引入需要的头文件
#include <vector>       
#include <algorithm>   // 为了使用copy_if()算法
#include <iostream>

using namespace std;

int main()
{
	// 定义总商品清单
    vector<string> vecGoods;

    // 文具类货物清单
    vector<string> vecStationaries = {"Pen","Erase","Pencil"};

    // 办公用品类商品清单
    vector<string> vecOfficeSupplies = {"Folder","Pen","Notepad"};

    // 根据源容器的数据多少调整目标容器的大小
    vecGoods.resize( vecStationaries.size() + vecOfficeSupplies.size() );
    
    // 使用sort()算法对源容器进行排序
    sort(vecStationaries.begin(), vecStationaries.end());
    sort(vecOfficeSupplies.begin(), vecOfficeSupplies.end());

    // 使用set_union()算法将源容器中的数据合并到目标容器中
    // set_union()算法返回的迭代器指向的是合并后的有效数据的结束位置
    auto itend = set_union( 
		vecStationaries.begin(),
		vecStationaries.end(),// 第一个容器的范围
		vecOfficeSupplies.begin(),
		vecOfficeSupplies.end(), // 第二个容器的范围
		vecGoods.begin());  // 目标容器的起始位置

    // 输出合并后的商品
    for(auto it = vecGoods.begin(); 
		it != itend;  // 以set_union()算法返回的迭代器作为结束位置
		++it)
    {
		cout<<*it<<endl;
    }

    return 0;
}