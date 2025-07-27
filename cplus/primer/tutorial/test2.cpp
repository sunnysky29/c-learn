#include <iostream>
using namespace std;

void q_2_3(){
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;   // 32
    cout << u - u2 << endl;   
    cout << "-------------------" << endl;
    int i = 10, i2 = 42;
    cout << i2 - i << endl;  // 32
    cout << i - i2 << endl;  //-32
    cout << i - u << endl;
    cout << u - i << endl;
}



void e2_5() {
    char c = 'a';
    wchar_t wc = L'a';

    cout << "char: " << c << endl;
    // 使用 wcout 输出宽字符
    wcout << L"wchar_t: " << wc << endl;

}

void e2_8(){
// 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。
    cout << 2 << "\115\012";  // \012, 八进制， ASCII -- 10（\n）; \115, 77 (M)
    cout << 2 << "\t\115\012";
   
}

void e2_9(){
    int input_value;
    cin >> input_value;
    cout << "input_value : " << input_value << endl;

    int val;
    while (cin >> val) {
        cout << "val = " << val << endl;
}
}




string global_str;
int global_int;

void e2_10(){
    int local_int;              // danger!!!! 声明但未初始化, 则不确定该值， 会有潜在问题
    string local_str;        // ✅ 默认构造为空字符串

    // 示例使用
    cout << "global_int = " << global_int << endl;
    cout << "local_int = " << local_int << endl;
    cout << "local_str = \"" << local_str << "\"" << endl;

}

void e2_14(){
    // 变量 作用域
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    cout << i << " " << sum << endl;  /// 100 45
}


#include <climits>
void test(){
    // int *p1;  //野指针（wild pointer），未初始化，不安全
    // cout << "Wild pointer address: " << p1 << endl; // 打印 p 的随机值
    // *p1 = 10;
    // cout << *p1 << endl;

    // int *p2 = nullptr; // 空指针，ok


    // 指针变量理解
    int a = 42;
    int *p = &a;
    cout << "a 的值: " << a << endl;
    cout << "a 的地址: " << &a << endl;

    cout << "p 的值（指向的地址）: " << p << endl;
    cout << "通过 p 访问 a 的值: " << *p << endl;

    cout << "p 自己的地址: " << &p << endl;



    // 获取类型大小信息
    cout << "=== 类型大小（字节）===\n";
    cout << "sizeof(int):  " << sizeof(int) << endl;
    cout << "sizeof(long): " << sizeof(long) << endl;
    // 显示范围
    cout << "\n=== 类型范围 ===\n";
    cout << "int 范围:  [" << INT_MIN << ", " << INT_MAX << "]\n";
    cout << "long 范围: [" << LONG_MIN << ", " << LONG_MAX << "]\n";
    
    //  const 限定符使用 
    int i2 =8;
    // 声明一个指向 i2 的 const 指针
    int *const p2 = &i2;
    cout << "p2 = " << p2 << endl;           // 输出地址
    cout << "*p2 = " << *p2 << endl;         // 输出 42

    // ✅ 合法：可以通过 p2 修改 i2 的值
    *p2 = 100;
    cout << "i2 = " << i2 << endl;           // 输出 100
    // // ❌ 错误：不能修改 p2 本身（不能重新指向）
    // int i3 = 200;
    // p2 = &i3;  // ❌ 错误：p2 是 const 指针，不能重新赋值

    

}


int main() {
    // test();

    q_2_3();
    e2_5();
    e2_8();
    // e2_9();

    e2_10();
    e2_14();


    test();


    return 0;
}