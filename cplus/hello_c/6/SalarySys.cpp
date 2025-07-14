// SalarySys.cpp
// 引入需要的头文件
#include <ctime>  	// 使用其中的时间函数
#include <string> 	// 使用字符串对象
#include <iostream>  // 屏幕输入输出
#include <fstream>	// 文件输入输出
#include <climits>   // 引入INT_MAX

using namespace std;

// 枚举员工的级别
enum EmpLevel
{
	enumOfficer = 1,  	// 高级员工
	enumStaff = 2		// 一般员工
};

// 员工类
class Employee
{
public:
	// 构造函数，根据员工的姓名和入职年份构造对象
	Employee(string strName,int nY)
		:m_strName(strName),m_nYear(nY) // 设定员工的姓名和入职年份
	{}
	// Employee类的行为，这些行为都是供外界调用的接口，
	// 所以将其访问级别设定为public
public:
	// 获得员工姓名
	string GetName() const
	{
		return m_strName;
	}
	// 获得员工入职年份
	int GetYear() const
	{
		return m_nYear;
	}
	// 获得员工级别
	EmpLevel GetLevel() const
	{
		return m_nLevel;
	}
	// 获得员工工资，因为这个行为同具体的员工类相关，
	// 不同的派生类有不同的行为（计算方法），所以在基类Employee中只是
	// 用纯虚函数表示接口，具体行为由其派生类实现
	virtual int GetSalary() = 0;

	// GetWorkTime()只是供自身和自己的派生类似用，所以将其
	// 访问级别设定为protected
protected:	
	// 获得在职时间，也就是现在年份减去入职年份
	int GetWorkTime() const
	{
		// 获得现在的年份 
		time_t t = time(nullptr); // 获取当前时间
		tm timeinfo;                  // 定义 tm 结构体
		if (localtime_s(&timeinfo, &t) == 0) 
		{  
			// time()函数获得的时间是以1900年为起点，所以这里需要
			// 加上1900表示现在的年份。同时，不满一年按照一年计算，所以最后要加1
			return (timeinfo.tm_year + 1900) - m_nYear + 1; 
		}
		else
		{
			return -1;
		}
	}
	// Employee类的属性
	// 因为这些属性也同样应当是其派生类具有的，需要由基类遗传给
	// 它的派生类，所以这里使用protected访问级别，允许其派生类继承这些属性
protected:
	string m_strName; 	// 姓名
	int m_nYear;			// 入职年份
	EmpLevel m_nLevel;	// 级别
};

// 高级员工类
// 因为高级员工也是员工的“一种”，所以它可以从Employee类采用public派生
class Officer : public Employee
{
public:
	// 构造函数
	// 直接调用基类Employee的构造函数，完成相同部分属性的构建
	Officer(string strName, int nY)
		:Employee(strName,nY)
	{
		// 进行派生类独有的构建工作，设定员工的特定级别
		m_nLevel = enumOfficer;
	}
public:	
	// 对基类的纯虚函数进行重写，具体实现员工计算工资的行为
	virtual int GetSalary() override
	{
		// 对于高级员工，每年涨5000元工资
		return GetWorkTime()*5000;
	}
};
// 普通员工类
class Staff : public Employee
{
public:
	Staff(string strName, int nY)
		:Employee(strName,nY)
	{
		m_nLevel = enumStaff;
	}
public:
	// 不同的派生类对相同的行为有不同的实现，
	// 这就是类的多态机制的体现
	virtual int GetSalary() override
	{
		// 普通员工，每年涨1000元工资
		return GetWorkTime()*1000;
	}
};


// ...

// 定义SalarySys中数组的最大数据量，
// 也就是SalarySys最多能处理多少个员工数据
const int MAX = 100000;


// 工资管理类SalarySys
class SalarySys
{
public:
	// 构造函数，对属性进行初始化
	SalarySys()
		:m_nCount(0), // 设定当前数据量为0
		m_strFileName("SalaryData.txt") // 设定员工数据文件名
	{
		// 对数组进行初始化，使得数组中都是nullptr
		for(long i = 0; i < MAX; ++i)
		{
			m_arrEmp[i] = nullptr;
		}

		// 读取员工数据文件
		Read();
	}

	// 析构函数，完成清理工作
	~SalarySys()
	{
		// 将员工数据写入文件，以备下次读取
		Write();
		// 释放数组中已经创建的员工对象
		for(long i = 0; i < m_nCount; ++i)
		{
			delete m_arrEmp[i];  // 释放对象
			m_arrEmp[i] = nullptr;	// 将指针设置为nullptr
		}
	}
	// SalarySys的公有行为
public:
	// 从员工数据文件读取已经输入的数据
	int Read()
	{
		// 用于文件读取的中间临时变量
		string strName = "";
		int nLevel = 0;
		int nYear = 0;

		// 读取的数据个数
		int i = 0;

		// 打开数据文件
		ifstream in(m_strFileName);
		if(in.is_open()) // 判断是否成功打开文件
		{
			// 如果打开文件成功，构造无限循环进行读取
			while(true)
			{
				// 分别读取姓名、级别和入职年份
				in>>strName>>nLevel>>nYear;

				// 判断是否读取正确，如果读取错误，
				// 例如读取到达文件末尾，则结束读取
				if(!in) 
					break; // 跳出读取循环

				// 根据读取的员工级别，分别创建不同的员工对象，
				// 并保存到m_arrEmp数组进行管理
				if( enumOfficer == nLevel)
				{
					// 根据员工姓名和入职年份，创建高级员工对象
					m_arrEmp[i] = new Officer(strName,nYear);
					++i; // 记录已经读取的数据数量
				}
				else if ( enumStaff == nLevel)
				{
					m_arrEmp[i] = new Staff(strName,nYear);
					++i; // 记录已经读取的数据数量
				}

				// 如果读取的数量大于数组容量，则结束读取，否则继续下一次读取
				if(i >= MAX)						
					break;
			}
			// 读取完毕，关闭文件
			in.close();
		}
		// 输出读取结果并返回读取的数据个数
		cout<<"已读取"<<i<<"个员工数据"<<endl;
		m_nCount = i;  // 记录数组中有效数据的个数

		return i;
	}

	// 将员工数据写入文件
	void Write()
	{
		// 打开数据文件作为输出
		ofstream o(m_strFileName);
		if(o.is_open())
		{
			// 如果成功打开文件，则利用for循环逐个输出数组中保存的数据
			for(long i = 0;i < m_nCount; ++i)
			{
				Employee* p = m_arrEmp[i];
				// 输出各个员工的各项属性，以Tab间隔
				// 输出一位员工的数据后，末尾输出endl换行
				o<<p->GetName()<<"\t" 	// 名字
					<<p->GetLevel()<<"\t"	// 级别
					<<p->GetYear()<<endl;	// 入职年份
			}
			// 输出完毕，关闭文件
			o.close();
		}
	}	

	// 手工输入员工数据
	int Input()
	{
		// 提示输入
		cout<<"请输入员工信息（名字 级别(1-一般员工,2-高级员工) 入职年份），例如：Wanggang 1 1982"<<endl;
		cout<<"-1表示输入结束"<<endl;

		// 新输入的数据保存在数组已有数据之后，
		// 所以这里将已有数据个数m_nCount作为输入起点
		// 又因为i在for循环之后还需要用到，所以定义在for循环之前
		long i = m_nCount;

		for(; i < MAX; ++i) // 初始化语句留空
		{ 
			// 利用for循环逐个输入
			cout<<"请输入"<<i<<"号员工的信息："<<endl;

			// 根据输入的数据创建具体的员工对象，并保存到数组 
			string strName = "";
			int nL = 0;
			int nY = 0;
			// 获取用户输入
			cin>>strName>>nL>>nY;

			// 对输入情况进行判断处理
			if(!cin) // 如果输入错误，则重新输入
			{
				cout<<"输入错误，请重新输入"<<endl;
				cin.clear(); // 清理输入标志位
				cin.sync();	// 清空键盘缓冲区
				--i; // 本次输入作废，不计算在内
				continue; // 直接开始下一次输入循环
			}
			else // 输入正确
			{

				// 检查是否输入结束
				if("-1" == strName)
				{
					break; // 结束输入循环
				}

				// 根据输入的数据，创建具体的员工对象并保存到数组
				if(enumOfficer == nL)
					m_arrEmp[i] = new Officer(strName,nY);
				else if(enumStaff == nL)
					m_arrEmp[i] = new Staff(strName,nY);
				else  // 员工级别输入错误
				{
					cout<<"错误的员工级别，请重新输入"<<endl;
					--i;
					cin.clear(); // 清理输入标志位
					cin.sync();	// 清空键盘缓冲区
					continue;
				}
			}
		}
		// 输入完毕，调整当前数组中的数据量
		m_nCount = i;

		// 返回本次输入完成后的数据个数
		return m_nCount;
	}

	// 获得最高工资的员工对象
	Employee* GetMax()
	{
		// 表示结果的指针，初始值为nullptr
		Employee* pMax = nullptr;
		// 设定一个假想的当前最大值，也就是最小的int类型数据值
		int nMax = INT_MIN;
		// 用for循环遍历数组中的每一个对象
		for(long i = 0;i < m_nCount; ++i)
		{
			// 如果当前对象的工资高于当前最大值nMax，则将当前对象的工资
			// 作为新的当前最大值，并将当前对象的指针作为结果保存
			// 这里使用的是基类Employee的指针调用GetSalry()虚函数来获得
			// 当前对象的工资，而实际上，它将动态地调用这个指针所指向的实际对象的
			// 相应函数来完成工资的计算。换言之，如果这个指针指向的是Officer对象，
			// 就会调用Officer类的GetSalary()函数，如果指向的是Staff对象，
			// 就会调用Staff类的GetSalary()函数。这样就实现了不同等级
			// 的员工，不同的工资计算方式，使用统一的调用方式。

			if(m_arrEmp[i]->GetSalary() > nMax)
			{
				// 则将当前对象记录为结果对象
				pMax = m_arrEmp[i];
				// 并将当前对象的工资记录为当前最大值
				nMax = pMax->GetSalary();
			}
		}
		// 返回指向拥有最高工资的员工对象的指针
		return pMax;
	}

	// 查询员工工资
	void Find()
	{
		// 构造无限循环进行查询
		while(true)
		{
			// 查询的姓名
			string strName = "";
			// 输入提示
			cout<<"请输入要查询的员工名字（-1表示结束查询）："<<endl;
			// 获取用户输入的员工姓名
			cin>>strName;

			// 对用户输入进行检查
			if(!cin) // 如果输入错误，提示重新输入
			{
				cout<<"输入错误，请重新输入"<<endl;
				cin.clear();
				cin.sync();
				continue;  // 开始下一次查询
			}
			else if("-1" == strName) // 如果查询结束
			{
				// 查询结束，用break结束查询循环
				cout<<"查询完毕，感谢使用！"<<endl;
				break; 
			}
			// 记录是否找到查询的员工
			bool bFind = false;
			// 用for循环遍历所有员工对象，逐个进行比对查找
			for(long i = 0;i < m_nCount;++i)
			{
				// 获得指向当前对象的指针
				Employee* p = m_arrEmp[i];
				// 判断当前对象的名字是否与查询条件相同
				if(strName == p->GetName())
				{
					// 输出符合查询条件的员工信息 
					cout<<"员工姓名："<<p->GetName()<<endl;
					cout<<"员工工资："<<p->GetSalary()<<endl;
					bFind = true; // 记录本次查询成功
					break;	// 跳出for循环结束查询		// 结束循环
				}
			}

			// 如果本次没有找到，则提示用户重新输入
			if(!bFind) 
			{
				cout<<"无法找到名字为"<<strName<<"的员工。"<<endl;
				cout<<"请核对姓名，重新输入"<<endl;
			}	
		}
	}
	// SlarySys类的属性
	// 因为这些属性都只是供SalarySys类访问，
	// 所以其访问级别设定为private
private:
	// 数据文件名，为了防止被错误修改，所以使用const关键字修饰
	// 使用const修饰的成员变量，必须在类构造函数的初始化列表中进行初始化
	// 或者也可以在定义时直接赋值初始化
	const string m_strFileName;   
	Employee* m_arrEmp[MAX];  // 保存员工对象指针的数组
	int m_nCount = 0; // 数组中已有的员工对象数，定义时直接初始化
};

// ...

int main()
{
	// 创建一个SalarySys对象
	// 在构造函数中，它会首先去读取数据文件中的员工数据，
	// 完成““从文件读取”这一用例
	SalarySys sys;

	// 让用户输入数据，完成“手工输入”用例
	sys.Input();

	// 调用SalarySys的GetMax()函数获得工资最高的员工对象，
	// 完成“计算最大值”用例
	Employee* pMax = sys.GetMax();
	if(nullptr != pMax)
	{
		cout<<"工资最高的员工是："<<endl;
		cout<<"名字："<<pMax->GetName()<<endl;
		cout<<"工资："<<pMax->GetSalary()<<endl;
	}

	// 调用SalarySys类的Find()函数，完成“查询工资”用例
	sys.Find();

	// 最后，当sys对象析构的时候，会调用自己的Write()函数，
	// 完成“输出数据到文件”用例
	return 0;
}

