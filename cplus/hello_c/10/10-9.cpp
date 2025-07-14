// "算法"老师带来的一堂别开生面的体育课
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 学生类，描述学生的属性和行为
class Student
{
public:
    // 默认构造函数 
    Student() 
    { 
    };
    // 接受姓名和身高作为参数的构造函数，
    // 可以设定对象的姓名和身高属性
    Student( const string strName, const int nHeight )
        : m_strName(strName), m_nHeight(nHeight) {};
// 对象的行为
public:
    // 获取姓名
    string GetName() const
    {
        return m_strName;
    }
    // 获取身高
    int GetHeight() const
    {
        return m_nHeight;
    }
    // 设置身高
    void SetHeight(const int nHeight)
    {
        m_nHeight = nHeight;
    }
    // 向屏幕输出，报告名字和身高
    void Report() const
    {
        cout<<"我是"<<m_strName
		<<"，身高"<<m_nHeight<<endl;
    }
// 对象的属性
private:
    string m_strName = "";  	// 姓名
    int m_nHeight = 0;      	// 身高
};

// 排序的规则：按照身高排序，
// 高个儿的站左边，低个儿的站右边
bool sortbyHeight(const  Student& st1, const Student& st2 )
{
    // 两两之间比较一下身高
    return st1.GetHeight() < st2.GetHeight();
}

// 报数函数
void CountOff(const Student& st)
{
	static int nNum = 0; // 计数
	++nNum;  // 每次增加1
	cout<<nNum<<endl;  // 报告在队伍中的序号
	st.Report();  // 调用Student对象的Report()函数，报告姓名和身高
}

// 捉迷藏函数，判断Student对象的名字是否为"ZhangSan"
bool findZhangSan(const Student& st)
{
	return st.GetName() == "ZhangSan";
}

// 增加身高函数，将Student对象的身高增加50厘米
Student IncreaseHeight(Student& st)
{
    // 获取原来的身高
    int nHeight = st.GetHeight();
    // 在原身高的基础上增加50厘米，设置为新的身高
    st.SetHeight(nHeight + 50);
    
    return st;
}

int main()
{
	// 我和我的同学们
	Student st1("ZhangSan", 125);
	Student st2("LiShi", 133);
	Student st3("WangWu", 118);

	// 老师用push_back()函数将我们召集到vector容器中
	vector<Student> vecStu;  // 保存所有Student对象的容器
	vecStu.push_back( st1 );
	vecStu.push_back( st2 );
	vecStu.push_back( st3 );

	// 隔壁班的同学也要加入
	vector<Student> vecStuC2;
      Student st4("XiaoMing", 124);
      vecStuC2.push_back( st4 );
		
	// 扩大我们所在容器的容量，为新来的同学腾出点地方
	vecStu.resize( vecStu.size() + vecStuC2.size() );
	// 将新同学对象追加复制到我们的容器末尾中，欢迎新同学
	copy_backward( vecStuC2.begin(), vecStuC2.end(), vecStu.end());

	// 按照老师的排序规则排好队伍
	sort(vecStu.begin(), vecStu.end(), sortbyHeight);
	
	// 让容器中的每个对象都调用自己的Report()函数，
	// 报出自己的姓名和身高
	for_each( vecStu.begin(), vecStu.end(),CountOff);
	
	// 捉迷藏，从容器中找到名字为“ZhangSan”的Student对象
	auto it = find_if(vecStu.begin(),vecStu.end(), findZhangSan);
	// 如果找到，报告自己的名字和身高
	if(it != vecStu.end())
	{
		cout<<"找到了！"<<endl;
		(*it).Report();
     }
	else
	{
		cout<<"没有找到。"<<endl;
	}
        
	// 过家家，每个人的身高都增加50厘米，瞬间变成大人模样
	transform(vecStu.begin(),vecStu.end(),vecStu.begin(),IncreaseHeight);
        
	// 身高增加后，每个人都报告一下自己的姓名和新的身高
	for_each( vecStu.begin(), vecStu.end(),
		// 使用Lambda表达式调用Student对象的Report()函数
		// 具体规则请参考后文11.3小节的介绍
		[](const Student& st) { 
			st.Report();
		});
    
	return 0;
}