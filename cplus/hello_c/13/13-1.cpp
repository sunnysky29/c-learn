#include <cstring>  // 为了使用strlen()函数
// 完成后的String类
class String
{
public:
	String(const char* str = nullptr)	// 通用构造函数
	{
		// 首先对参数的有效性进行检查
		// 是否进行必要的参数检查，是判断一个程序员是否有经验的标志
		if (nullptr == str)
		{
			// 如果传入的参数为nullptr，则构造一个空字符串
			m_pData = new char[1];
			m_pData[0] = '\0'; 	// 唯一的字符为字符串结束符
		}
		else
		{
			// 根据传入的字符串长度申请内存
			// 这里需要注意的是，申请的内存长度应该在
			// 源字符串长度的基础上加1，因为字符串末尾还有一个结束符
			m_pData = new char[strlen(str) + 1];
			// 复制字符串
			strcpy(m_pData,str);
		}
	}
	String(const String& other)     	// 拷贝构造函数
	{
		// 申请内存
		m_pData = new char[strlen(other.m_pData) + 1];
		// 复制字符串
		strcpy(m_pData,other.m_pData);
	}
	~String()     	// 析构函数
	{
		// 释放字符串
		delete[] m_pData;
	}
	String& operator=(const String& rhs)	// 赋值运算操作符函数
	{
		// 判断是否为自己给自己赋值，如果是，则直接返回
		// 代码中是否有这个判断，这是程序员是否有足够经验的标志
		if(this == &rhs)
			return *this;

		// 删除原有数据
		delete[] m_pData;
		// 为新的数据申请内存
		m_pData = new char[strlen(rhs.m_pData) + 1];
		// 复制字符串
		strcpy(m_pData,rhs.m_pData);

		return *this;
	}
	// ...
private:
	char* m_pData = nullptr;     	// 指向字符数据的指针
};

int main()
{
	// 使用String类...
	return 0;
}