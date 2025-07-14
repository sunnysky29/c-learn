#include <iostream>

using namespace std;

// 键盘
class Keyboard
{
public:
    // 接收用户键盘输入
    void Input()
    {
        cout<<"键盘输入"<<endl;
    }
};

// 显示器
class Monitor
{
public:
    // 显示画面
    void Display()
    {
        cout<<"显示器输出"<<endl;
    }
};

// 电脑
class Computer
{
public:
    // 用键盘、显示器组合一台电脑
    Computer( Keyboard* pKeyboard,
                Monitor* pMonitor )
    {
        m_pKeyboard = pKeyboard;
        m_pMonitor = pMonitor;
    }
    // 电脑的行为
    // 其具体动作都交由其各个组成部分来完成
    // 键盘负责用户输入
    void Input()
    {
        m_pKeyboard->Input(); 
    }
    
    // 显示器负责显示画面
    void Display() 
    {
        m_pMonitor->Display();
    }
// 电脑的各个组成部分
private:
    Keyboard* 	m_pKeyboard = nullptr;	// 键盘
    Monitor* 	m_pMonitor = nullptr;  	// 显示器
// 其他组成部件对象
};

int main()
{
    // 先创建键盘和显示器对象
    Keyboard  keyboard;
    Monitor monitor;
    // 用键盘和显示器对象组合成电脑
    Computer com(&keyboard,&monitor);

    // 电脑的输入和输出，实际上最终是交由键盘和显示器去完成
    com.Input();
    com.Display();

    return 0;
}
