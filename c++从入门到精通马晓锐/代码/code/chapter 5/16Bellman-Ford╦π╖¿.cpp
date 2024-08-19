#include <bits/stdc++.h>
using namespace std;

//物流网点的个数、双向通行道路的个数、单向通行道路的个数
int n, m1, m2;
//起点、终点
int s, t;
//道路的个数m=2*m1+m2
int m;
//每条道路的起点、终点、长度
int u[30005], v[30005], w[30005];
//d[i]表示从起点s出发到点i的最短路径长度
int d[105];

void Bellman_Ford() {
    //初始化
    int inf = 1000000000;
    for (int i = 0; i < n; i++)d[i] = inf;
    d[s] = 0;
    //重复n-1次
    for (int k = 0; k < n - 1; k++) {
        //枚举每一条道路，将其衔接到某条最短路径末尾
        for (int i = 0; i < m; i++) {
            d[v[i]] = min(d[v[i]], d[u[i]] + w[i]);
        }
    }
}

int main() {
    //输入
    cin >> n >> m1 >> m2;
    cin >> s >> t;
    m = 0;
    for (int i = 0; i < m1; i++) {
        cin >> u[m] >> v[m] >> w[m];
        m++;
        u[m] = v[m - 1], v[m] = u[m - 1], w[m] = w[m - 1];
        m++;
    }
    for (int i = 0; i < m2; i++) {
        cin >> u[m] >> v[m] >> w[m];
        m++;
    }
    //求解
    Bellman_Ford();
    //输出
    cout << d[t] << endl;
    return 0;
}