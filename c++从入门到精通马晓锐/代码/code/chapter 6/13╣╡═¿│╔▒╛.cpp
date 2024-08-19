#include <bits/stdc++.h>
using namespace std;


//公司中员工的总数、能够顺畅沟通的最大沟通成本
int n, k;
//to[i]记录所有与员工i可以直接沟通（上司或下属）的员工
vector<int> to[100005];
//vis[i]表示员工i是否曾被作为根节点计算过
bool vis[100005];


namespace ROOT{
    //weight[i]表示以i为根节点的最大子树大小
    int weight[100005];
    //size[i]表示本次深度优先搜索中节点i下方的子树大小
    int size[100005];
    //path存储了当前子树包含的所有节点
    vector<int> path;
    //深度优先搜索，用于求重心
    void dfs(int u, int last_node) {
        path.emplace_back(u);
        size[u] = 1;
        weight[u] = 0;
        for (auto v : to[u]) {
            if (v != last_node and !vis[v]) {
                dfs(v, u);
                size[u] += size[v];
                weight[u] = max(weight[u], size[v]);
            }
        }
    }
    //求重心
    int get_next_root(int u) {
        //调用深度优先搜索求u所在子树中每个节点下方的子树大小
        path.clear();
        dfs(u, -1);
        //求重心
        int centre = path[0];
        for (auto v : path) {
            //不要忘了另一侧的子树哦
            weight[v] = max(weight[v], size[u] - size[v]);
            if (weight[v] < weight[centre])centre = v;
        }
        return centre;
    }
}


namespace PAIR{
    //depth[i]表示从根节点员工开始到员工i的沟通成本，即深度
    int depth[100005];
    //depth_array记录当前这个树所有节点的深度
    vector<int> depth_array;
    //以u为起点，计算其下方的点的深度，last_node为前一个点
    void calculate_depth(int u, int last_node) {
        //把当前深度存储到数组depth_array中
        depth_array.emplace_back(depth[u]);
        for (auto v : to[u]) {
            //要避免走回头路
            if (v != last_node and !vis[v]) {
                depth[v] = depth[u] + 1;
                calculate_depth(v, u);
            }
        }
    }
    //计算以root为根节点的子树中，有多少点之间的距离不超过k
    int get_pairs(int root, int k) {
        //调用calculate_depth函数计算每个点的深度
        depth_array.clear();
        depth[root] = 0;
        calculate_depth(root, -1);
        //排序
        sort(depth_array.begin(), depth_array.end());
        //使用两个指针扫描depth_array，计算有多少对数的和不超过k
        int sum = 0, l = 0, r = (int)depth_array.size() - 1;
        while (l < r) {
            if (depth_array[l] + depth_array[r] <= k) {
                sum += r - l;
                l++;
            }else r--;
        }
        return sum;
    }
}


//计算以root为根节点的子树中，横跨多个子树的点对中有多少距离不超过k
int divide(int root) {
    int ans = 0;
    vis[root] = true;
    ans += PAIR::get_pairs(root, k);
    for (auto v : to[root]) {
        if (!vis[v]) {
            ans -= PAIR::get_pairs(v, k - 2);
            //子树换根后递归求解
            int next_root = ROOT::get_next_root(v);
            ans += divide(next_root);
        }
    }
    return ans;
}


int main() {
    //输入
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int leader;
        cin >> leader;
        //把i与leader的关系存储下来，注意是双向的
        to[i].emplace_back(leader);
        to[leader].emplace_back(i);
    }
    //求解并输出
    int root = ROOT::get_next_root(0);
    cout << divide(root) << endl;
    return 0;
}