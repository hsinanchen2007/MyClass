#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000000;
//计算x^n%1000000000
long long power(long long x, int n) {
    //递归的边界:x^0=1
    if (n == 0)return 1;
    //计算x^m(m=n/2取整)
    int m = n / 2;
    long long a = power(x, m);
    if (n % 2 == 0) {
        //如果n是偶数，那么x^n=(x^m)*(x^m)
        return a * a % MOD;
    } else {
        //如果n是奇数，那么x^n=(x^m)*(x^m)*x
        return a * a % MOD * x % MOD;
    }
}

int main() {
    int n;
    //输入
    cin >> n;
    //求解并输出
    cout << power(2, n - 1) << endl;
    return 0;
}