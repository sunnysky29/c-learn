#include <iostream>
#include <string>
#include <vector>


using namespace std;





void e3_2_1(){
    string s;
	while (getline(cin,s))  // 一次读取一行
	{
		cout << s << endl;
	}
	
}
void e3_2_2(){
    string s;
	while ((cin >> s))  // 一次读取一个词
	{
		cout << s << endl;
	}
	
}

void e3_14(){
    vector<int> v;
	int i;
	while (cin >> i)  // 输入完数据后，按 Ctrl + D
	{
		v.push_back(i);
	}

    // 清除输入流状态（重要！否则后续 cin 可能仍为 fail）
    cin.clear();

    // 可选：忽略输入缓冲区中的残留字符（如换行符）
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "\n读取完成，共 " << v.size() << " 个整数。\n";

    // 显示 vector 内容（推荐方式：范围 for）
    cout << "vector 内容： \n";
    for (const auto& elem : v) {
        cout << elem << endl;
    }
}


void test(){
    string s1 = "Hello";
    cout << "s1: " << s1 << endl;
    s1[0] = '2';           // 修改第一个字符
    cout << "s1 修改后: " << s1 << endl;  // 输出: hello World

    char st[12] = "fundamental";

    
    vector<int> vec = {1000, 2000, 3000, 4000, 5000};
    cout << "std::vector vec: ";
    for (int i = 0; i < 5; ++i) {
        cout << vec[i] << " ";  // 使用下标访问
    }
    cout << endl;

}


int main() {
    test();

    // e3_2_1();
    // e3_2_2();

    // e3_14();




    return 0;
}