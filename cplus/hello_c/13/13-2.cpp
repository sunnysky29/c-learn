#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // 保存学生成绩的容器
    vector<int> vecScore = {67,88,94,46,82};
    // 将学生成绩数据保存到容器
    // ...
    // 保存及格人数的变量
    int nPass = 0;
    // 使用for循环遍历容器，用迭代器访问容器中的数据，逐个进行判断
    for(auto it = vecScore.begin(); it != vecScore.end(); ++it )
    {
        // 将符合条件的数据统计在内
        if( *it >= 60 )
            nPass += 1;
    }
    
    cout<<"及格人数是"<<nPass<<endl;

    return 0;
}