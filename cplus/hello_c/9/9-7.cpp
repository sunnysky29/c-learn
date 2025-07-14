#include <iostream>
#include <map> // 引入map容器所在的头文件
#include <string>

using namespace std;

class Employee
{
public:
    // 默认构造函数
    Employee() {}
    // 用姓名做参数的构造函数
    Employee(string strName)
     : m_strName(strName)
    { 
    }

    string GetName()
    {
        return m_strName;
    }

    int GetSalary()
    {
        return m_nSalary;
    }
private:
    string m_strName;
    int m_nSalary = 0;
};

int main()
{
    // 创建一个map容器对象mapEmp
    // 这个容器需要保存“int-Employee”形式的数据对
    // 所以以int和Employee作为map类模板的类型参数
    // 使用初始化列表对map容器进行初始化
    map<int,Employee> mapEmp = 
	   {   // map容器的初始数据元素
		{1001, Employee()},   // 默认的Employee对象
		{1002, Employee("Zhang")},
		{1003, Employee("Wang")}
	   };

    // 创建一个Employee对象
    Employee emp1;
    // 使用pair<int, Employee>模板类建立员工号1和员工对象emp1的联系，形成数据对
    // 将pair<int, Employee>模板类创建的对象插入map容器中
    mapEmp.insert(pair<int, Employee>(1, emp1 ));

    // 利用for循环访问map容器中的所有数据
    for( auto it = mapEmp.begin(); 
        it != mapEmp.end(); ++it )
    {
        // 通过迭代器输出数据对的键和值
        cout<<"当前员工号是："<<it->first<<endl;
        cout<<"姓名："<<it->second.GetName()<<endl;
        cout<<"工资："<<it->second.GetSalary()<<endl;
    }
 
    return 0;
}