/*
 * @author: shenke
 * @date: 2021/1/8
 * @project: Codeforces
 * @desp: 
 */

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
const double pi = 3.1415926;

// 小数取模
double mod(double a, double b) {
    return a - (int) (a / b) * b;
}

// 小数 gcd（最大公约数）
double gcd(double x, double y) {
    if (y <= 0.0001) return x;
    return gcd(y, mod(x, y));
}

double x, y, x2, y2, x3, y3;

int main() {
    cin >> x >> y >> x2 >> y2 >> x3 >> y3;
    // 计算三角形三条边长
    double a = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    double b = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
    double c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double p = (a + b + c) / 2;
    // 通过r=(abc)/(4s)得出外接圆半径
    double r = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
    // 分别求出以三条边为低，外接圆半径为腰的三角形的顶角角度
    double angle1 = acos(1 - (a * a) / (2 * r * r));
    double angle2 = acos(1 - (b * b) / (2 * r * r));
    double angle3 = 2 * pi - angle1 - angle2;
    // 题目所示的以正多边形边长为低接圆半径为腰的三角形的顶角角度
    double angle = gcd(angle1, gcd(angle2, angle3)) / pi * 180;
    // 求出正多边形的边长
    double side = sqrt(2 * r * r - 2 * r * r * cos(angle / 180 * pi));
    double P = (r * 2 + side) / 2;
    // 计算面积
    double s = sqrt(P * (P - r) * (P - r) * (P - side)) * (360 / angle);
    // 保留6位小数输出
    cout << fixed << setprecision(6) << s;
    return 0;
}
