#include <iostream>
using namespace std;

// 基类 base
class base {
public:
    int a;
protected:
    int b;
private:
    int c;
private:
    static int count; // 静态成员：计数

public:
    // 构造函数
    base(int a_ = 0, int b_ = 0, int c_ = 0) : a(a_), b(b_), c(c_) {
        count++; // 创建对象时计数+1
    }

    // 静态成员函数：管理count
    static int manage() {
        return count;
    }

    // 成员函数：输出成员
    void print() {
        cout << "base: a=" << a << ", b=" << b << ", c=" << c
            << ", count=" << count << endl;
    }

    // 析构函数
    ~base() {
        count--; // 销毁对象时计数-1
    }
};
// 静态成员初始化
int base::count = 0;


// 公有继承 derived1
class derived1 : public base {
public:
    derived1(int a_ = 0, int b_ = 0, int c_ = 0) : base(a_, b_, c_) {}

    void testAccess() {
        cout << "derived1（public继承）访问：" << endl;
        cout << "a=" << a;          // 公有继承：基类public成员→子类public
        cout << ", b=" << b;        // 公有继承：基类protected成员→子类protected
        // cout << ", c=" << c;    // 基类private成员，子类无法访问
        cout << endl;
    }
};


// 保护继承 derived2
class derived2 : protected base {
public:
    derived2(int a_ = 0, int b_ = 0, int c_ = 0) : base(a_, b_, c_) {}

    void testAccess() {
        cout << "derived2（protected继承）访问：" << endl;
        cout << "a=" << a;          // 保护继承：基类public成员→子类protected
        cout << ", b=" << b;        // 保护继承：基类protected成员→子类protected
        // cout << ", c=" << c;    // 基类private成员，子类无法访问
        cout << endl;
    }
};


// 私有继承 derived3
class derived3 : private base {
public:
    derived3(int a_ = 0, int b_ = 0, int c_ = 0) : base(a_, b_, c_) {}

    void testAccess() {
        cout << "derived3（private继承）访问：" << endl;
        cout << "a=" << a;          // 私有继承：基类public成员→子类private
        cout << ", b=" << b;        // 私有继承：基类protected成员→子类private
        // cout << ", c=" << c;    // 基类private成员，子类无法访问
        cout << endl;
    }
};


// 主函数测试（继承权限+构造/析构顺序）
int main() {
    // 1. 测试继承权限
    derived1 d1(1, 2, 3);
    d1.testAccess();
    cout << "derived1外部访问a: " << d1.a << endl; // public继承：a对外可见

    derived2 d2(4, 5, 6);
    d2.testAccess();
    // cout << d2.a; // protected继承：a对外不可见

    derived3 d3(7, 8, 9);
    d3.testAccess();
    // cout << d3.a; // private继承：a对外不可见


    // 2. 测试构造/析构顺序
    cout << "\n构造/析构顺序测试：" << endl;
    {
        derived1 temp(10, 20, 30);
        // 构造：先base，后derived1
        // 析构：先derived1，后base
    }


    // 3. 测试静态成员count
    cout << "\n当前对象总数：" << base::manage() << endl;

    return 0;
}