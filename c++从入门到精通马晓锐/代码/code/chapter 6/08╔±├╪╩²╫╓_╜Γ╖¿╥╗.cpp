#include <bits/stdc++.h>
using namespace std;

//1000000007
const long long mod = 1e9 + 7;
long long n;
long long f[100005][2];

int main() {
    //输入
    cin >> n;
    //初始化
    f[0][0] = 8;
    f[0][1] = 1;
    //用动态规划计算
    for (int i = 1; i < n; i++) {
        f[i][0] = (9 * f[i - 1][0] + f[i - 1][1]) % mod;
        f[i][1] = (f[i - 1][0] + 9 * f[i - 1][1]) % mod;
    }
    //输出
    cout << f[n - 1][0] << endl;
    return 0;
}