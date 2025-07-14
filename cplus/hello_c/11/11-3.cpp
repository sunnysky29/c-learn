#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
public:
    Student(int nHeight) : m_nHeight(nHeight) {}
    Student() {}
    int GetHeight() const
    {
        return m_nHeight;
    }
private:
    int m_nHeight; // 身高
};
// 定义一个函数对象类
// 用于统计容器中所有Student对象的身高
class AverageHeight
{
public:
    // 构造函数，对类的成员变量进行合理的初始化
    AverageHeight() 
        : m_nCount(0), m_nTotalHeight(0) {};

    // 定义函数调用操作符“()”
    // 在其中完成统计的功能
    void operator () ( const Student& st )
    {
        // 将当前对象的身高累加到总身高中
        // 这里的m_nTotalHeight记录了上次累加的结果
        // 这就是函数失去的记忆
        m_nTotalHeight += st.GetHeight();
        // 增加已经统计过的Student对象的数目
        ++m_nCount;
    }
    
    // 接口函数，获得所有统计过的Student对象的平均身高
    float GetAverageHeight() 
    {
        if ( 0 != m_nCount )
              return (float)GetTotal()/GetCount();
	        else
             return 0.0f;
    }
    // 获得函数对象类的各个成员变量
    int GetCount() const
    {
        return m_nCount;
    }
    int GetTotal() const
    {
        return m_nTotalHeight;
    }

// 函数对象类的成员变量
// 用来保存函数执行过程中的状态数据
private:
    int m_nCount = 0;         	// 记录已经统计过的对象的数目
    int m_nTotalHeight = 0; 	// 记录已经统计过的身高总和
};


// 利用mycount_if()算法统计vector容器中的数据
int main()
{
    // 将数据添加到容器
    vector<int> vecStu = {180,176,195,164};
    
    // 定义变量，用于保存函数执行过程中的状态数据
    int nTotalHeight = 0;
    int nCount = 0;
    // 在for_each()算法中使用Lambda表达式，统计身高
    for_each( vecStu.begin(), vecStu.end(), 
        [&](const Student& st)     			// Lambda表达式
        {
            nTotalHeight += st.GetHeight(); 	// 直接访问外部数据，累计身高
            ++nCount;
        });

    // 输出统计结果
    if( 0 != nCount )
    {
        cout<<nCount<<"个学生的平均身高是："
            <<(float)nTotalHeight/nCount<<endl;
    }

    return 0;
}
