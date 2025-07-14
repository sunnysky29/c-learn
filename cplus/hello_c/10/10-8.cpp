// 引入需要的头文件
#include <vector>       
#include <algorithm>   // 为了使用copy_if()算法
#include <iostream>

using namespace std;

// 创建表示矩形的Rect类
class Rect
{
public:
	Rect() {};  // 默认构造函数     
    // 构造函数，设定矩形的长和宽
    Rect( float fW, float fH )
        : m_fW(fW), m_fH(fH) {};
    
    // 重载“<”操作符，用于比较两个矩形的大小
    // 它的参数是另外一个Rect对象的引用
    bool operator < (const Rect& r ) const
    {
        // 计算两个矩形的面积
        float fArea = GetArea(); // 自身的面积
        // 另一个矩形的面积
        float fAreaOhter = r.GetArea();
        // 返回两个面积比较的结果作为两个矩形比较的结果
        return fArea < fAreaOhter;
    }
    // 获得矩形的面积
    float GetArea() const
    {
        return m_fW * m_fH;
    }
    // 获得矩形的宽和高
    float GetW() const
    {
        return m_fW;
    }
    float GetH() const
    {
        return m_fH;
    };
    // 获取矩形的周长
    float GetGirth() const
    {
        return (GetW() + GetH()) * 2;
    }
// 矩形的属性：长和宽
private:
    float m_fW;
    float m_fH;
};

int main()
{
    // 创建保存Rect对象的容器
    vector<Rect> vecRect;
    // 将多个Rect对象添加到容器中
    vecRect.push_back( Rect(3, 4) );
    vecRect.push_back( Rect(6, 7) );
    vecRect.push_back( Rect(8, 1) );
    // 对容器中的Rect对象进行排序
    // 这里使用默认的“<”操作符，按照面积排序
    sort( vecRect.begin(), vecRect.end() );

    // 输出排序后的矩形
    for(Rect& rect : vecRect)
    {
        cout<<"矩形的面积是:"<<rect.GetArea()<<endl;
    }
    
    return 0;
}

