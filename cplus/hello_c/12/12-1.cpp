#include <iostream> 
#include <cstring>  // 为了使用内存复制函数memcpy()
using namespace std;

// 用于管理内存的类
class MemoryBlock
{
public:
	// 构造函数，根据参数申请相应大小的内存资源
	MemoryBlock(const unsigned int nSize)
	{
		cout<<"创建对象，申请内存资源"<<nSize<<"字节"<<endl;
		m_nSize = nSize;
		m_pData = new char[nSize];
	}
	MemoryBlock(const MemoryBlock& other)
	{
		// ... 
	}
	// 析构函数，释放管理的内存资源
	~MemoryBlock()
	{
		cout<<"销毁对象";
		if(0 != m_nSize) 			// 如果拥有内存资源
		{
			cout<<"，释放内存资源"<<m_nSize<<"字节";
			delete[] m_pData; 	// 释放内存资源
			m_nSize = 0; 
		}
		cout<<endl;
	}
	// 赋值操作符，完成对象的复制
	// 这里的参数是一个左值引用
	MemoryBlock& operator = (const MemoryBlock& other)
	{
		// 判断是否自己给自己赋值
		if(this == &other)
			return *this;
		// 第一步，释放已有内存资源
		cout<<"释放已有内存资源"<<m_nSize<<"字节"<<endl;
		delete[] m_pData;
		// 第二步，根据赋值对象的大小重新申请内存资源
		m_nSize = other.GetSize();
		cout<<"重新申请内存资源"<<m_nSize<<"字节"<<endl;
		m_pData = new char[m_nSize];
		// 第三步，复制数据
		cout<<"复制数据"<<m_nSize<<"字节"<<endl;
		memcpy(m_pData,other.GetData(),m_nSize);

		return *this;
	}
public:
	// 获取相关数据的成员函数
	unsigned int GetSize() const
	{
		return m_nSize;
	}
	char* GetData() const
	{
		return m_pData;
	}
private:
	unsigned int m_nSize = 0;	// 内存块的大小
	char* m_pData = nullptr;			// 指向内存块的指针
};

// 根据大小创建相应的MemoryBlock对象
MemoryBlock CreateBlock(const unsigned int nSize)
{
	// 创建相应大小的对象
	MemoryBlock mem(nSize);
	// 给内存中填满字符'A' 
	memset(mem.GetData(),'A',mem.GetSize());
	// 返回创建的对象
	return mem;
}
int main()
{
	// 用于保存函数返回值的block变量
	MemoryBlock block(256);
	// 用函数创建特定大小的MemoryBlock对象
	// 并赋值给block变量
	block = CreateBlock(1024);
	cout<<"创建的对象大小是"
		<<block.GetSize()<<"字节"<<endl;

	return 0;
}
