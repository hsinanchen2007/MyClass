#include <bits/stdc++.h>
using namespace std;

//货物数量、关系数量
int n, m;
//pre[v]存储所有可以堆放在货物v下方的货物
vector<int> pre[100005];
//nex[v]存储所有可以堆放在货物v上方的货物
vector<int> nex[100005];
//h[v]表示货物v放在最上方时最多可以堆放的货物数量
int h[100005];

//拓扑排序
vector<int> TopologicalSort() {
    //in_deg[v]记录了当前状态v之前还有多少状态未计算
    vector<int> in_deg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto v : nex[u])in_deg[v]++;
    }
    //node存储了所有可以计算但还未计算的状态
    vector<int> node;
    for (int u = 0; u < n; u++) {
        if (in_deg[u] == 0)node.push_back(u);
    }
    //permutation存储拓扑排序的结果
    vector<int> permutation;
    while (node.size() > 0) {
        //从node中取出一个可以直接计算的状态
        int u = node.back();
        node.pop_back();
        //将该状态放入排序结果中
        permutation.push_back(u);
        //将该状态从图中删除，更新相关的in_deg
        for (auto v : nex[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0)node.push_back(v);
        }
    }
    //返回结果
    return permutation;
}

//动态规划
int calculate_max_height(vector<int> permutation) {
    int ans = 0;
    for (auto v : permutation) {
        for (auto u : pre[v]) {
            h[v] = max(h[v], h[u]);
        }
        h[v]++;
        ans = max(ans, h[v]);
    }
    return ans;
}

int main() {
    //输入
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pre[a].push_back(b);
        nex[b].push_back(a);
    }
    //求解
    vector<int> permutation = TopologicalSort();
    int ans = calculate_max_height(permutation);
    //输出
    cout << ans << endl;
    return 0;
}