/*
可见性 
在 C++ 中，class 的默认访问级别是 private。 

*/


#include <iostream>
using namespace std;

// =======================
// 基类：演示可见性
// =======================
class Entity {
private:
    int private_data;
    void private_func() {
        cout << "[Entity] private_func called\n";
    }

protected:
    int protected_data;
    void protected_func() {
        cout << "[Entity] protected_func called\n";
    }

public:
    int public_data;
    
    // 构造函数
    Entity() : private_data(100), protected_data(200), public_data(300) {
        cout << "[Entity] Constructor\n";
        
        // ✅ 类内部：可以访问所有成员
        private_func();      // OK: private 可以在类内调用
        protected_func();    // OK
        cout << "private_data = " << private_data << endl;
    }
};

// =======================
// 派生类：Player
// =======================
class Player : public Entity {
public:
    Player() {
        cout << "[Player] Constructor\n";

        // ❌ 不能访问 private 成员
        // private_data = 10;           // ❌ 错误！private 不可访问
        // private_func();              // ❌ 错误！

        // ✅ 可以访问 protected 成员
        protected_data = 999;           // OK!
        protected_func();               // OK!

        // ✅ 可以访问 public 成员
        public_data = 888;              // OK!
        cout << "protected_data = " << protected_data << endl;
        cout << "public_data = " << public_data << endl;
    }

    void test_access() {
        cout << "\n[Player] test_access() called:\n";

        // protected 成员可以在子类中使用
        cout << "Current protected_data = " << protected_data << endl;
        cout << "Current public_data = " << public_data << endl;

        // private_data 仍然无法访问
        // cout << private_data; // ❌ 编译错误
    }
};

// =======================
// 外部函数：模拟类外访问
// =======================
void external_code(Player& p) {
    cout << "\n[External Code] Trying to access members:\n";

    // ❌ private: 不能访问
    // cout << p.private_data;     // ❌ 错误
    // p.private_func();           // ❌ 错误

    // ❌ protected: 不能访问（即使 p 是 Player 对象）
    // cout << p.protected_data;   // ❌ 错误！protected 不能在类外访问
    // p.protected_func();         // ❌ 错误

    // ✅ 只有 public 成员可以在外部访问
    cout << "public_data = " << p.public_data << endl;  // ✅ OK
    p.public_data = 1234;                                // ✅ OK
}

// =======================
// 主函数：演示所有情况
// =======================
int main() {
    cout << "=== Creating Player object ===\n";
    Player p;

    cout << "\n=== From external function ===\n";
    external_code(p);

    cout << "\n=== From Player method ===\n";
    p.test_access();

    // 总结表格输出
    cout << "\n=== 可见性总结 ===\n";
    cout << "访问位置       | private | protected | public\n";
    cout << "---------------|---------|-----------|--------\n";
    cout << "类内部         |   ✅     |    ✅      |   ✅\n";
    cout << "派生类内部     |   ❌     |    ✅      |   ✅\n";
    cout << "类外部（函数） |   ❌     |    ❌      |   ✅\n";

    return 0;
}