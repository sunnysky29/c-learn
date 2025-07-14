#include <vector>	 // 为了使用vector容器	
#include <algorithm>  // 为了使用remove()和replace_if()算法
#include <iostream>

using namespace std;

int main()
{
	// 保存C1和C2班级成绩的容器
    vector<int> vecScoreC1;
    vector<int> vecScoreC2;

    // 对容器进行操作，将各个班级的成绩保存到各自的容器中
    // ...

    // 保存所有成绩的成绩总表容器
    vector<int> vecScore;
    // 根据各个分容器的大小，重新设定总容器的容量，
    // 使它可以容纳即将复制进来的所有数据
    vecScore.resize( vecScoreC1.size() + vecScoreC2.size() );
    // 将第一个容器vecScoreC1中的数据复制到vecScore中
    auto lastit = copy(vecScoreC1.begin(), 
        vecScoreC1.end(), // 复制的范围
        vecScore.begin() ); // 复制的目标位置
    // 将第二个容器vecScoreC2中的数据追加到vecScore的末尾
    copy(vecScoreC2.begin(), 
        vecScoreC2.end(), 
        lastit );  // 以上一次复制的结束位置作为第二次复制的开始位置

	return 0;
}