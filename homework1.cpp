//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// 二维点类 Point2D
//class Point2D {
//private:
//    double x, y; // 坐标
//
//public:
//    // 构造函数（默认+带参）
//    Point2D(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
//
//    // 移动坐标
//    void move(double dx, double dy) {
//        x += dx;
//        y += dy;
//    }
//
//    // 输出坐标（const保证不修改成员）
//    void show() const {
//        cout << "Point2D: (" << x << ", " << y << ")" << endl;
//    }
//
//    // 友元函数：计算两点欧式距离
//    friend double distance(const Point2D& p1, const Point2D& p2) {
//        double dx = p1.x - p2.x;
//        double dy = p1.y - p2.y;
//        return sqrt(dx * dx + dy * dy);
//    }
//
//    // 提供子类访问父类私有成员的接口（或设为protected）
//    double getX() const { return x; }
//    double getY() const { return y; }
//};
//
//// 三维点类 Point3D（继承自Point2D）
//class Point3D : public Point2D {
//private:
//    double z; // 三维坐标z
//
//public:
//    // 构造函数（复用父类构造）
//    Point3D(double x_ = 0, double y_ = 0, double z_ = 0)
//        : Point2D(x_, y_), z(z_) {
//    }
//
//    // 重写move（增加z轴移动）
//    void move(double dx, double dy, double dz) {
//        Point2D::move(dx, dy); // 调用父类move
//        z += dz;
//    }
//
//    // 重写show（输出三维坐标）
//    void show() const {
//        cout << "Point3D: (" << getX() << ", " << getY() << ", " << z << ")" << endl;
//    }
//
//    // 友元函数：计算三维点欧式距离
//    friend double distance(const Point3D& p1, const Point3D& p2) {
//        double dx = p1.getX() - p2.getX();
//        double dy = p1.getY() - p2.getY();
//        double dz = p1.z - p2.z;
//        return sqrt(dx * dx + dy * dy + dz * dz);
//    }
//};
//
//// 主函数测试
//int main() {
//    // 测试Point2D
//    Point2D p2d1(1, 2), p2d2(4, 6);
//    p2d1.show();
//    p2d2.show();
//    cout << "Distance between p2d1 and p2d2: " << distance(p2d1, p2d2) << endl;
//    p2d1.move(2, 3);
//    p2d1.show();
//
//    cout << "------------------------" << endl;
//
//    // 测试Point3D
//    Point3D p3d1(1, 2, 3), p3d2(4, 6, 8);
//    p3d1.show();
//    p3d2.show();
//    cout << "Distance between p3d1 and p3d2: " << distance(p3d1, p3d2) << endl;
//    p3d1.move(2, 3, 4);
//    p3d1.show();
//
//    return 0;
//}