#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
//检验首项为a0，公差为d的等差数列与a数列不一致的个数是否至多为3
bool check(int a0, int d) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != a0 + i * d)num++;
    }
    return num <= 3;
}

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //C++的随机数生成器
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n - 1);
    //重复随机抽取
    while (true) {
        //随机抽取两个多米诺骨牌
        int x = distribution(generator), y = distribution(generator);
        //如果不小心抽到了同一个，跳过这步循环，重新抽取
        if (x == y)continue;
        //如果公差不是整数，跳过这步循环，重新抽取
        if ((a[y] - a[x]) % (y - x) != 0)continue;
        //计算公差d和首项a0
        int d = (a[y] - a[x]) / (y - x), a0 = a[x] - x * d;
        //检验每一项是否都是正数，骨牌的高度不可能是0或负数
        if (a0 <= 0 or a0 + (n - 1) * d <= 0)continue;
        //检验是否抽到了两个没有被换掉的多米诺骨牌，如果是，输出结果并停止程序
        if (check(a0, d)) {
            for (int i = 0; i < n; i++) {
                cout << a0 + i*d << " \n"[i == n - 1];
            }
            break;
        }
    }
    return 0;
}