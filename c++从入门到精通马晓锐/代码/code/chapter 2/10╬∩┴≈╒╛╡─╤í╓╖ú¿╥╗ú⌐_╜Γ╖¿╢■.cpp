#include <bits/stdc++.h>
using namespace std;

//题目中的变量
int n, m, x[20], y[20], a[20], u[20], v[20];
//用来标记每个居民点是否在服务范围中
bool flag[20];
//记录新建物流站i后，新增覆盖的居民点个数
int new_num[20];
//判断物流站i能否服务居民点j
bool can_serve(int i, int j) {
    return (x[i] - u[j]) * (x[i] - u[j]) + (y[i] - v[j]) * (y[i] - v[j]) <= a[i] * a[i];
}
int solve() {
    //当前覆盖的居民点个数
    int num = 0;
    //需要建造的物流站个数
    int station = 0;
    while (num < m) {
        //选一个包含最多未被覆盖的居民点的物流站，将它作为一个修建点
        int new_station = 0;
        for (int i = 0; i < n; i++) {
            new_num[i] = 0;
            for (int j = 0; j < m; j++) {
                if (flag[j] == false and can_serve(i, j))new_num[i]++;
            }
            if (new_num[i] > new_num[new_station])new_station = i;
        }
        //在该处新建物流站，更新相关变量
        for (int j = 0; j < m; j++) {
            if (flag[j] == false and can_serve(new_station, j)) {
                flag[j] = true;
                num++;
            }
        }
        station++;
    }
    return station;
}

int main() {
    //输入
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> u[j] >> v[j];
    }
    //求解并输出
    cout << solve() << endl;
    return 0;
}