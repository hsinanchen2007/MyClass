#include <bits/stdc++.h>
using namespace std;

//物资的箱数、可以运输的最大重量
int n, W;
//每箱物资的重量和价值
int w[10005], v[10005];
//f[i][j]表示只考虑前i箱物资，载重为j时可以运输的最大物资价值
int f[105][10005];

int max_value() {
    //依次考虑第i箱物资
    for (int i = 1; i <= n; i++) {
        //依次考虑每个可能的载重量
        for (int j = 0; j <= W; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    }
    //计算最终的答案
    int ans = 0;
    for (int j = 0; j <= W; j++)ans = max(ans, f[n][j]);
    return ans;
}

int main() {
    //输入
    int package_num;
    cin >> package_num >> W;
    for (int i = 0; i < package_num; i++) {
        int M, W, V;
        cin >> M >> W >> V;
        for (int j = 0; j < M; j++) {
            n++;
            w[n] = W;
            v[n] = V;
        }
    }
    //求解并输出
    cout << max_value() << endl;
    return 0;
}