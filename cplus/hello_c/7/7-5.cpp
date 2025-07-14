#include <iostream>

using namespace std;

// 矩形类
class Rect
{
public:
		// ...

		// 获得矩形面积，不应该修改类的数据，所以在函数末尾加上const修饰
        int GetArea() const
		{
			// 试图在const修饰的成员函数内修改类的成员变量
            // 会导致一个编译错误
            m_nW = 10; 
            return m_nW * m_nH; // 只读访问成员变量
		}
		// 设置矩形的长和宽，
        // 函数参数nW和nH只是用于传入数据，所以加上const修饰
        // 但在函数内部，会修改类的成员数据，所以没有const修饰函数本身
        void SetRect(const int nW,const int nH)
		{
			m_nW = nW; // 修改成员变量
			m_nH = nH;
		}
private: // 设置私有访问级别保护数据
		int m_nW = 0;
    	int m_nH = 0;
};


int main()
{
    // 定义一个const修饰的常量对象
    const Rect rect;
    // 在常量对象上调用非const修饰的成员函数是非法的
    rect.SetRect(3,4);
    // 在常量对象上调用const修饰的成员函数是合法的	
    int n = rect.GetArea();

    return 0;
}

