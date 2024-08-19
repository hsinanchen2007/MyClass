#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000000;
//计算x^n%1000000000
long long power(long long x, int n) {
    //递归的边界:x^0=1,x^1=x
    if (n == 0)return 1;
    else if (n == 1)return x;
    //m=n/2取整
    int m = n / 2;
    //计算x^m
    long long a = power(x, m);
    //计算x^(n-m)
    long long b = power(x, n - m);
    //x^n=(x^m)*x^(n-m)
    return a * b % MOD;
}

int main() {
    int n;
    //输入
    cin >> n;
    //求解并输出
    cout << power(2, n - 1) << endl;
    return 0;
}