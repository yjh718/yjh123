#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Triangle {
private:
    double a, b, c;  // 私有数据成员：三条边长

public:
    // 1. 初始化函数：初始化边长并校验合法性（边长为正）
    void Init(double sideA, double sideB, double sideC) {
        if (sideA > 0 && sideB > 0 && sideC > 0) {
            a = sideA;
            b = sideB;
            c = sideC;
            cout << "三角形初始化成功，边长：a=" << a << ", b=" << b << ", c=" << c << endl;
        }
        else {
            cout << "边长输入非法（必须为正数），已默认初始化为直角三角形（a=3, b=4, c=5）" << endl;
            a = 3;
            b = 4;
            c = 5;
        }
    }

    // 2. 读函数（getter）：获取三条边长
    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    // 3. 写函数（setter）：修改边长，带合法性校验（边长为正）
    void setSideA(double sideA) {
        if (sideA > 0) {
            a = sideA;
            cout << "边长a修改成功，当前a=" << a << endl;
        }
        else {
            cout << "边长a输入非法（必须为正数），保持原a=" << a << endl;
        }
    }

    void setSideB(double sideB) {
        if (sideB > 0) {
            b = sideB;
            cout << "边长b修改成功，当前b=" << b << endl;
        }
        else {
            cout << "边长b输入非法（必须为正数），保持原b=" << b << endl;
        }
    }

    void setSideC(double sideC) {
        if (sideC > 0) {
            c = sideC;
            cout << "边长c修改成功，当前c=" << c << endl;
        }
        else {
            cout << "边长c输入非法（必须为正数），保持原c=" << c << endl;
        }
    }

    // 4. 判断能否构成三角形：两边之和大于第三边
    bool isTriangle() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // 5. 计算周长：三边之和（仅当能构成三角形时有效）
    double perimeter() const {
        if (isTriangle()) {
            return a + b + c;
        }
        else {
            cout << "当前边长无法构成三角形，周长计算无效！" << endl;
            return 0;
        }
    }

    // 6. 计算面积：海伦公式（仅当能构成三角形时有效）
    double area() const {
        if (!isTriangle()) {
            cout << "当前边长无法构成三角形，面积计算无效！" << endl;
            return 0;
        }
        double p = perimeter() / 2;  // 计算半周长p
        // 海伦公式：S = sqrt(p*(p-a)*(p-b)*(p-c))
        double area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }

    // 7. 判断三角形类型：1=直角，2=锐角，3=钝角，0=无法构成三角形
    int typeTriangle() const {
        // 先判断是否能构成三角形
        if (!isTriangle()) {
            return 0;
        }

        // 步骤1：确定最长边（假设c为最长边，通过交换确保）
        double x = a, y = b, z = c;
        if (x > z) swap(x, z);  // 若x（原a）>z（原c），交换x和z
        if (y > z) swap(y, z);  // 若y（原b）>z（当前最长边），交换y和z

        // 步骤2：通过平方关系判断类型（处理浮点精度问题，使用1e-6作为阈值）
        const double EPS = 1e-6;  // 浮点精度阈值（避免因精度误差导致判断错误）
        double x2y2 = x * x + y * y;  // 两短边的平方和
        double z2 = z * z;            // 最长边的平方

        if (fabs(x2y2 - z2) < EPS) {  // 两短边平方和 ≈ 最长边平方（直角三角形）
            return 1;
        }
        else if (x2y2 > z2) {       // 两短边平方和 > 最长边平方（锐角三角形）
            return 2;
        }
        else {                      // 两短边平方和 < 最长边平方（钝角三角形）
            return 3;
        }
    }

    // 辅助函数：显示三角形完整信息（边长、是否为三角形、周长、面积、类型）
    void displayInfo() const {
        cout << "\n===== 三角形信息汇总 =====" << endl;
        cout << "边长：a=" << fixed << setprecision(2) << a
            << ", b=" << fixed << setprecision(2) << b
            << ", c=" << fixed << setprecision(2) << c << endl;

        cout << "能否构成三角形：" << (isTriangle() ? "是" : "否") << endl;

        if (isTriangle()) {
            cout << "周长：" << fixed << setprecision(2) << perimeter() << endl;
            cout << "面积：" << fixed << setprecision(2) << area() << endl;

            // 根据typeTriangle()结果显示类型
            int type = typeTriangle();
            cout << "三角形类型：";
            switch (type) {
            case 1: cout << "直角三角形" << endl; break;
            case 2: cout << "锐角三角形" << endl; break;
            case 3: cout << "钝角三角形" << endl; break;
            }
        }
        cout << "=========================\n" << endl;
    }
};

// 主函数：测试三角形类功能
int main() {
    // 1. 测试直角三角形（3,4,5）
    Triangle t1;
    t1.Init(3, 4, 5);
    t1.displayInfo();

    // 2. 测试钝角三角形（2,3,4）
    Triangle t2;
    t2.Init(2, 3, 4);
    t2.displayInfo();

    // 3. 测试锐角三角形（5,5,5，等边三角形）
    Triangle t3;
    t3.Init(5, 5, 5);
    t3.displayInfo();

    // 4. 测试无法构成三角形的情况（1,2,4）
    Triangle t4;
    t4.Init(1, 2, 4);
    t4.displayInfo();

    // 5. 测试边长修改功能
    Triangle t5;
    t5.Init(6, 8, 10);  // 初始为直角三角形
    t5.setSideC(11);     // 修改边长c为11（变为钝角三角形）
    t5.displayInfo();

    return 0;
}