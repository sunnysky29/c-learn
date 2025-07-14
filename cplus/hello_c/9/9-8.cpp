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

    // 定义要查找的键
    int nKey = 1;  
    // 使用find()函数查找键，返回指向拥有这个键的数据对的迭代器
    // 如果map容器中没有这个键，则返回指向容器末尾位置的迭代器 
    auto it = mapEmp.find( nKey );

    // 查看迭代器是否指向容器末尾位置，以此判断是否找到相应的数据对
    if (mapEmp.end() == it )
    {
        // 如果迭代器指向容器末尾位置，就表示没有找到对应的数据对
        cout<<"无法找到键为"<<nKey<<"的数据对。"<<endl;
    }
    else 
    {
        // 如果迭代器指向其他位置，则表示找到相应的数据对，
        // find()函数返回的迭代器指向的就是这个数据对的位置 
        cout<<"找到键为"<<nKey<<"的数据对。"<<endl;
        // 通过迭代器访问这个数据对的值，也就是Employee对象
        cout<<"姓名："<<it->second.GetName()<<endl;
        cout<<"工资："<<it->second.GetSalary()<<endl;
    } 
    
    return 0;
}