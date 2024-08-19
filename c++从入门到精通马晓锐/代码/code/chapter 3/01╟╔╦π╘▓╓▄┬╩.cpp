#include <bits/stdc++.h>
using namespace std;

int main() {
    //C++的随机数生成器
    default_random_engine generator;
    uniform_real_distribution<double> distribution(-1, 1);
    //实验次数与点在圆内的次数
    int n = 1000000, m = 0;
    //进行n次随机试验
    for (int i = 0; i < n; i++) {
        double x = distribution(generator), y = distribution(generator);
        if (x * x + y * y < 1)m++;
    }
    //根据实验结果输出圆周率的近似值
    cout << fixed << setprecision(10) << (double)m * 4 / n << endl;
    return 0;
}