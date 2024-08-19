#include <bits/stdc++.h>
using namespace std;

//矩阵个数
int n;
//矩阵的行数和列数
int m[105];
//f[l][r]表示计算A[l]A[l+1]...A[r]需要的最少计算次数
int f[105][105];

void dp() {
    //注意for循环中的计算顺序哦
    for (int r = 0; r < n; r++) {
        for (int l = r - 1; l >= 0; l--) {
            f[l][r] = 1000000000;
            for (int i = l; i < r; i++) {
                f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r] + m[l] * m[i + 1] * m[r + 1]);
            }
        }
    }
}

int main() {
    //输入
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> m[i];
    }
    //求解
    dp();
    //输出
    cout << f[0][n - 1] << endl;
    return 0;
}