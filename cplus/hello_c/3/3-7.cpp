#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

// auto 是 C++11 中引入的关键字，
// 它的作用是让编译器根据初始化表达式自动推导变量类型 ，
// 从而简化代码、提高可读性和安全性。 

std::string demangle(const char* name) {
    int status = -1;
    char* demangled = abi::__cxa_demangle(name, nullptr, nullptr, &status);
    std::string result = (status == 0) ? demangled : name;
    free(demangled);
    return result;
}

int main()
{
    // 使用 auto 自动推导变量类型
    auto str = "你好，C++!";        // const char*
    auto num = 42;                  // int
    auto pi = 3.14159;              // double
    auto ch = 'A';                  // char
    auto flag = true;               // bool

    // 输出变量值和其推导出的类型
    cout << "str 的类型是: " << typeid(str).name() << " -> 值: " << str << endl;
    cout << "num 的类型是: " << typeid(num).name() << " -> 值: " << num << endl;
    cout << "pi 的类型是: " << typeid(pi).name() << " -> 值: " << pi << endl;
    cout << "ch 的类型是: " << typeid(ch).name() << " -> 值: " << ch << endl;
    cout << "flag 的类型是: " << typeid(flag).name() << " -> 值: " << (flag ? "true" : "false") << endl;
    cout  << "--------------" << endl;
    std::cout << "str 的类型是: " << demangle(typeid(str).name()) << std::endl;
    std::cout << "num 的类型是: " << demangle(typeid(num).name()) << std::endl;
    std::cout << "pi 的类型是: " << demangle(typeid(pi).name()) << std::endl;
    std::cout << "ch 的类型是: " << demangle(typeid(ch).name()) << std::endl;
    std::cout << "flag 的类型是: " << demangle(typeid(flag).name()) << std::endl;
    return 0;
}


