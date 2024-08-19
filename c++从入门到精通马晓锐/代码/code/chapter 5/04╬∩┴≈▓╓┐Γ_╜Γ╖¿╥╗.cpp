#include <bits/stdc++.h>
using namespace std;

//货物数量、关系数量
int n, m;
//pre[v]存储所有可以堆放在货物v下方的货物
vector<int> pre[100005];
//h[v]表示货物v放在最上方时最多可以堆放的货物数量
int h[100005];

int max_height(int v) {
    if (h[v] != 0)return h[v];
    else {
        for (auto u : pre[v]) {
            h[v] = max(h[v], max_height(u));
        }
        h[v]++;
        return h[v];
    }
}

int main() {
    //输入
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pre[a].push_back(b);
    }
    //求解
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, max_height(i));
    }
    //输出
    cout << ans << endl;
    return 0;
}