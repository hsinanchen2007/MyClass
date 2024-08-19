#include <bits/stdc++.h>
using namespace std;

//会议人数、分组数
int n, m;
//u[i][j]表示成员i与成员j争论所需的时间
int u[1005][1005];
//u矩阵的前缀和
int s[1005][1005];
//f[i][j]表示把前j个人分到前i组中需要的最短会议时间
int f[1005][1005];

//计算将成员l,l+1,...,r分到同一组进行会议需要的时间
int T(int l, int r) {
    return (s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1]) / 2;
}
//动态规划
void dp() {
    //把f[i][j]初始化为足够大的数
    int inf = 1e9;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = inf;
        }
    }
    //初始状态，0个人分到0个组开会需要0分钟
    f[0][0] = 0;
    //在状态转移中计算f[i][j]
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i - 1; k <= j - 1; k++) {
                if (f[i - 1][k] + T(k + 1, j) < f[i][j]) {
                    f[i][j] = f[i - 1][k] + T(k + 1, j);
                }
            }
        }
    }
}

int main() {
    //输入
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> u[i][j];
        }
    }
    //计算前缀和s
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = u[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    //动态规划
    dp();
    //输出
    cout << f[m][n] << endl;
    return 0;
}