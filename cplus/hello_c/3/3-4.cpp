// 引入随机数引擎和分布所在的头文件
#include <random>
#include <iostream>

// 使用std名字命名空间  
using namespace std;

int main()
{
    // 定义一个默认的随机数引擎
	default_random_engine reng; 
	// 构建一个从0到25之间的平均分布
	uniform_int_distribution<int>  uni_dist(0,25); 
		
	// 使用random_device设置随机数引擎的种子，
	// 以防止每次运行都产生相同的伪随机数序列
	random_device  rnd_device; 
	reng.seed(rnd_device());  

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
					
	return 0;
}