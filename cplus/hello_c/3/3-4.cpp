// 引入随机数引擎和分布所在的头文件
#include <random>  //c++ 标准库中关于随机数的头文件
#include <iostream>

// 使用std名字命名空间  
using namespace std;

int main()
{
	default_random_engine reng;  // 定义一个默认的随机数引擎
	// 0到8之间的平均分布，注意可以取到两端
	uniform_int_distribution<int>  uni_dist(0,8); 
		
	// 使用random_device设置随机数引擎的种子，
	// 以防止每次运行都产生相同的伪随机数序列
	random_device  rnd_device; 
	reng.seed(rnd_device());  

	// ========== 新增部分：运行100次并打印 ==========
    cout << "前20个随机数（0~8）：" << endl;
    for (int i = 0; i < 20; ++i)
    {
        int rand_num = uni_dist(reng);
        cout << rand_num << " ";

        // 每行打印10个数字，便于阅读
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl << "========================" << endl;

	// 验证码一共4位
	const int n = 4;	
    char code[n]; // 保存验证码的字符数组
	// 提示输入验证码
    cout<<"请输入下面的验证码："<<endl;
    // 利用for循环产生4个验证码字母字符
    for (int i = 0; i < n; ++i)
	{
    	// uni_dist(reng)表示让reng引擎按照uni_dist分布，
        // 产生取值在0到25之间呈平均分布的随机数
		// 然后在‘A’的基础上向后偏移，就得到了随机的验证码字母字符
        code[i] = 'A' + uni_dist(reng); 

        // 输出验证码字母字符
        cout<<code[i];
    }
    
    // ...
    cout<<endl;


}