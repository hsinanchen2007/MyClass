#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    //n=1 的情况需要单独处理
    if (n == 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false; //如果n能被i整除，那么n不是素数
    }
    return true;
}

int main() {
    //输入
    int n;
    cin >> n;
    //求解并输出
    if (isPrime(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}