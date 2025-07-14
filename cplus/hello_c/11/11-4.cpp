#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

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
		time_t t = time(0);
		struct tm* now = localtime(&t);
		// time()函数获得的时间是以1900年为起点，所以这里需要
		// 加上1900表示现在的年份。同时，不满一年按照一年计算，所以最后要加1
		return (now->tm_year + 1900) - m_nYear + 1; 

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


// 用容器和算法改写后的SalarySys类
class SalarySys
{
public:
	// 使用vector容器保存数据，构造函数不需要对其进行初始化
	// 直接读取数据到容器即可
	SalarySys()
		: m_strFileName("SalaryData.txt")
	{
		Read(); // 直接读取数据
	}
	// 析构函数
	~SalarySys()
	{
		// 保存数据到文件
		Write();
		// 析构对象，释放内存
		// 使用基于范围的序列for循环方便地访问容器中的Employee*指针
		for(Employee* p : m_vecEmp)
		{
			delete p;
		}
		// 用vector容器的clear()函数清空容器
		m_vecEmp.clear();
	}
private:
	// 读取数据，创建对象并保存到vector容器
	int Read()
	{
		// ...
        return 0;
	}

	// 将vector容器中的数据写入文件
	void Write()
	{
		ofstream o(m_strFileName);
		if(o.is_open())
		{
			// 使用序列基于范围的for循环遍历访问容器中的数据
			for(Employee* p : m_vecEmp)
			{
				o<<p->GetName()<<"\t"
					<<p->GetLevel()<<"\t"
					<<p->GetYear()<<endl;
			}

			o.close();
		}
	}	

public:
	// 输入数据
	int Input()
	{
		cout<<"请输入员工信息（名字 等级 入职年份）"<<endl;
		cout<<"例如：Lilei 1 1976，-1表示输入结束"<<endl;
		while(true) // vector不限制容量，所以可以使用无限循环构造输入循环
		{
			// 提示输入
			// 用size()函数动态地获得vector容器中数据的个数
			cout<<"请输入"<<m_vecEmp.size()<<"号员工的信息："<<endl;

			// 根据输入的数据创建对象，并保存到vector容器
			string strName = "";
			int nL = 0;
			int nY = 0;
			// 获取用户的输入
			cin>>strName>>nL>>nY;

			if(!cin) // 输入错误
			{
				cout<<"输入错误，请重新输入"<<endl;
				cin.clear();
				cin.sync();
				continue;
			}
			else
			{
				// 检查是否输入结束
				if("-1" == strName)
				{
					break;  // 结束输入
				}

				// 根据输入数据创建对象，并添加到vector容器
				AddEmployee(strName,nL,nY);
			}
		}
		// 返回当前容器中的数据量
		return m_vecEmp.size();
	}

	Employee* GetMax()
	{
		// 使用max_element()算法查找容器中的最大值
		// 代替原来的for循环遍历数组查找
		auto maxit = max_element(m_vecEmp.begin(),
			m_vecEmp.end(),
			// 配合算法使用的Lambda表达式，对算法进行自定义
			[](Employee* a, Employee* b) -> bool 
		{
			return a->GetSalary() < b->GetSalary();
		});
		// 如果容器中有数据，返回找到的指向最大值的指针
		if(m_vecEmp.end() != maxit)
		{
			return (*maxit);
		}
		else // 如果容器中没有数据，返回nullptr，表示没有最大值
		{
			return nullptr;
		}
	}

	// 查询员工工资
	void Find()
	{
		while(true)
		{
			string strName = "";
			// 输入提示
			cout<<"请输入要查询的员工名字（-1表示结束查询）："<<endl;
			// 获取用户输入
			cin>>strName;

			if(!cin) // 如果发生输入错误
			{
				cout<<"输入错误，请重新输入"<<endl;
				cin.clear();
				cin.sync();
				continue;
			}
			else if("-1" == strName) // 是否输入结束
			{
				// 查询结束，用break结束查询循环
				cout<<"查询完毕，感谢使用！"<<endl;
				break; 
			}

			// 使用find_if算法查找符合条件的员工数据
			// 代替原来的使用for循环遍历数组进行查找
			auto it = find_if(m_vecEmp.begin(),
				m_vecEmp.end(),
				// 用Lambda表达式对查找条件进行自定义
				[=](Employee* emp) -> bool
			{
				// 如果当前员工姓名与用户输入的姓名相同
				return emp->GetName() == strName;
			});
			// 根据查找结果进行不同的处理
			if(it != m_vecEmp.end())
			{
				// 找到符合条件的员工，输出用户查询的员工工资
				cout<<"员工姓名："<<(*it)->GetName()<<endl;
				cout<<"员工工资："<<(*it)->GetSalary()<<endl;
			}
			else // 如果未找到，则提示重新输入
			{
				cout<<"无法找到名字为"<<strName<<"的员工"<<endl;
			}
		}
	}
private:
	// 根据数据创建相应的员工对象，并添加到vector容器
	void AddEmployee(const string& strName, const int nL, const int nY)
	{
		if(enumOfficer == nL)
			// 使用push_back()函数将新创建的对象动态添加到vector容器
				m_vecEmp.push_back(new Officer(strName,nY));
		else if(enumStaff == nL)
			m_vecEmp.push_back(new Staff(strName,nY));
	}
private:
	const string m_strFileName;
	// 将原来固定大小的数组替换为可以动态改变大小的vector容器，节省资源
	// 同时省略了记录员工数据个数的成员变量m_nCount
	vector<Employee*> m_vecEmp;
};


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
