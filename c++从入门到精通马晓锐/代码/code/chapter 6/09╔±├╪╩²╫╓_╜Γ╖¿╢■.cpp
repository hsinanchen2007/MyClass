#include <bits/stdc++.h>
using namespace std;

//1000000007
const long long mod = 1e9 + 7;
long long n;
//矩阵
struct Matrix {
    long long value[2][2];
};
//矩阵乘法
Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.value[i][j] += A.value[i][k] * B.value[k][j];
                C.value[i][j] %= mod;
            }
        }
    }
    return C;
}
//计算矩阵x的n次方
Matrix power(Matrix x, int n) {
    Matrix ans = {{{1, 0}, {0, 1}}};
    while (n > 0) {
        if (n % 2 == 1)ans = mul(ans, x);
        n = n / 2;
        x = mul(x, x);
    }
    return ans;
}

int main() {
    //输入
    cin >> n;
    //计算
    Matrix A = {{{9, 1}, {1, 9}}};
    Matrix power_A = power(A, n - 1);
    long long ans = (power_A.value[0][0] * 8 + power_A.value[0][1]) % mod;
    //输出
    cout << ans << endl;
    return 0;
}