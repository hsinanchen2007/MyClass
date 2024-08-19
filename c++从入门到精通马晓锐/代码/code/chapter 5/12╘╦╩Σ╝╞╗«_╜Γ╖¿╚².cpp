#include <bits/stdc++.h>
using namespace std;

//物资的箱数、可以运输的最大重量
int n, W;
//每箱物资的重量和价值
int w[10005], v[10005];
//f[j]表示载重为j时可以运输的最大物资价值
int f[10005];

int max_value() {
    //依次考虑第i箱物资
    for (int i = 1; i <= n; i++) {
        //依次考虑每个可能的载重量
        for (int j = W; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    //计算最终的答案
    int ans = 0;
    for (int j = 0; j <= W; j++)ans = max(ans, f[j]);
    return ans;
}

int main() {
    //输入并拆分物资
    int package_num;
    cin >> package_num >> W;
    for (int i = 0; i < package_num; i++) {
        int M, W, V;
        cin >> M >> W >> V;
        //以二进制形式拆分物资
        for (int k = 1; k <= M; k *= 2) {
            M -= k;
            n++;
            w[n] = k * W;
            v[n] = k * V;
        }
        //如果还有剩余，单独打包这批物资
        if (M > 0) {
            n++;
            w[n] = M * W;
            v[n] = M * V;
        }
    }
    //求解并输出
    cout << max_value() << endl;
    return 0;
}