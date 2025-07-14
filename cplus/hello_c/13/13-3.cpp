#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // 保存学生成绩的容器
    vector<int> vecScore = {67,88,94,46,82};
    // 将学生成绩数据保存到容器
    // ...
    // 保存及格人数的变量
    int nPass = 0;
    // 使用for_each()算法结合Lambda表达式统计容器中的数据
    // for_each()算法实现遍历
    for_each(vecScore.begin(), vecScore.end(),
        [&](int nScore)    // Lambda表达式实现统计
        {
            if(nScore >= 60)
                nPass +=1;
        });
    
    cout<<"及格人数是"<<nPass<<endl;

    return 0;
}