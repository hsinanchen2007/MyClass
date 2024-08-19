#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000000;
//计算x^n%1000000000
long long power(long long x, int n) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * x) % MOD;
    }
    return ans;
}

int main() {
    int n;
    //输入
    cin >> n;
    //求解并输出
    cout << power(2, n - 1) << endl;
    return 0;
}