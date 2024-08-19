#include <bits/stdc++.h>
using namespace std;

//物流网点的个数、双向通行道路的个数、单向通行道路的个数
int n, m1, m2;
//起点、终点
int s, t;
//f[i][j]表示从i到j的最短路径长度
int f[105][105];

void Floyd() {
    //依次考虑第k个点
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //如果把点k插入到(i->j)的最短路径中能得到一条更短的路径
                //那么就更新f[i][j]
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}

int main() {
    //输入与初始化
    cin >> n >> m1 >> m2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //如果点i到点j没有道路，那么可以认为点i到点j有一条“很长”的道路
            f[i][j] = 1000000000;
        }
        f[i][i] = 0;
    }
    cin >> s >> t;
    int u, v, w;
    //输入所有双向通行的道路
    for (int i = 0; i < m1; i++) {
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = min(f[v][u], w);
    }
    //输入所有单向通行的道路
    for (int i = 0; i < m2; i++) {
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
    }
    //求解
    Floyd();
    //输出
    cout << f[s][t] << endl;
    return 0;
}