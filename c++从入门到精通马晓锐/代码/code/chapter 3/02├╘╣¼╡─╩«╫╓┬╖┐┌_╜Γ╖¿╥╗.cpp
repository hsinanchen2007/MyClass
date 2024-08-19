#include <bits/stdc++.h>
using namespace std;

//C++的随机数生成器
default_random_engine generator;
uniform_int_distribution<int> distribution(1, 3);

//利用随机数模拟小算到达火车站的过程，记录所需的时间
int MonteCarloSimulation(int a, int b, int c) {
    int ans = 0;
    while (true) {
        int r = distribution(generator);
        if (r == 1) {        //走第一条路
            ans += a;
        } else if (r == 2) { //走第二条路
            ans += b;
        } else {             //走第三条路
            ans += c;
            break;
        }
    }
    return ans;
}
int main() {
    //输入
    int a, b, c;
    cin >> a >> b >> c;
    //进行n次随机试验，计算所需时间的平均值
    int n = 100000;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (double)MonteCarloSimulation(a, b, c) / n;
    }
    //输出
    cout << sum << endl;
    return 0;
}