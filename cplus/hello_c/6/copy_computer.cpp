#include <iostream>
#include <string>
 
using namespace std;

// 键盘类，因为结构简单，我们使用struct来定义
struct Keyboard
{
    // 键盘的型号
    string m_strModel;
};

// 定义了拷贝构造函数的电脑类
class Computer
{
public:
    // 默认构造函数 
    Computer()
        : m_pKeyboard(nullptr),m_strModel("")
    {}
    // 拷贝构造函数，参数是const修饰的Computer类的引用 
    Computer(const Computer& com)
        // 直接使用初始化属性列表完成对象类型成员变量m_strModel的复制
        : m_strModel(com.m_strModel)	   
    {
        // 创建新对象，完成指针类型成员变量m_pKeyboard的复制
        // 获得已有对象com的指针类型成员变量m_pKeyboard
        Keyboard* pOldKeyboard = com.GetKeyboard();
        
	    // 以pOldKeyboard所指向的Keyboard对象为蓝本，
        // 创建一个新的Keyboard对象，并让m_pKeyboard指向这个对象
        if( nullptr != pOldKeyboard )
	   {
           // 这里Keyboard对象的复制使用的是Keyboard类的默认拷贝构造函数
            m_pKeyboard = new Keyboard(*(pOldKeyboard));
        }
        else
	   {
            m_pKeyboard = nullptr; // 如果没有键盘
	   }
    }

    // 析构函数，
    // 对于对象类型的成员变量m_strModel，会被自动销毁，无须在析构函数中进行处理
    // 对于指针类型的成员变量m_pKeyboard，则需要在析构函数中主动销毁
    ~Computer()
    {
        delete m_pKeyboard;
        m_pKeyboard = nullptr;
    }
    // 成员函数，设置或获得键盘对象指针
    void SetKeyboard(Keyboard* pKeyboard)
    {
        m_pKeyboard = pKeyboard;
    }
    Keyboard* GetKeyboard() const
    {
        return m_pKeyboard;
    }
    // 设置和获取电脑型号
    void SetModel(string model)
    {
        m_strModel = model;
    }
    string GetModel()
    {
        return m_strModel;
    }
private:
    // 指针类型的成员变量
    Keyboard* m_pKeyboard = nullptr;
    // 对象类型的成员变量
    string m_strModel = "";
};

int main()
{
    // 创建一个键盘对象
    Keyboard* pKeyboard = new Keyboard();
    // 设置键盘的型号
    pKeyboard->m_strModel = "KB 101";

    // 定义一个电脑对象
    Computer a;
    // 设置电脑型号
    a.SetModel("COM 100");
    // 为电脑设置键盘
    a.SetKeyboard(pKeyboard);

    // 以电脑对象a为蓝本，创建电脑对象b
    Computer b(a);
    
    // 验证新创建电脑对象b的型号跟之前的电脑对象a相同
    cout<<"电脑对象a的型号："<<a.GetModel()<<endl;
    cout<<"电脑对象a的键盘型号"<<a.GetKeyboard()->m_strModel<<endl;
    cout<<"电脑对象b的型号："<<b.GetModel()<<endl;
    cout<<"电脑对象b的键盘型号："<<b.GetKeyboard()->m_strModel;
    
    return 0;
}