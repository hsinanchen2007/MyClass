#include <bits/stdc++.h>
using namespace std;

//题目中的变量
int n, m, x[20], y[20], a[20], u[20], v[20];
//用来标记每个居民点是否在服务范围中
bool flag[20];
//判断物流站i能否服务居民点j
bool can_serve(int i, int j) {
    return (x[i] - u[j]) * (x[i] - u[j]) + (y[i] - v[j]) * (y[i] - v[j]) <= a[i] * a[i];
}
int solve() {
    //总方案数=2的n次方
    int max_s = 1 << n;
    int ans = n;
    for (int s = 0; s < max_s; s++) {
        int station = 0; //当前方案的物流站个数
        for (int j = 0; j < m; j++)flag[j] = false;
        int temp = s;
        for (int i = 0; i < n; i++) {
            if (temp % 2 == 1) {
                station++;
                //将物流站i服务范围内的每一个居民点打上标记
                for (int j = 0; j < m; j++) {
                    if (can_serve(i, j))flag[j] = true;
                }
            }
            temp /= 2;
        }
        //判断当前方案能否覆盖每一个居民点，并更新答案
        int num = 0;
        for (int j = 0; j < m; j++)if (flag[j])num++;
        if (num == m)ans = min(ans, station);
    }
    return ans;
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