#include <bits/stdc++.h>
using namespace std;

//物流站选址个数、线路长度
int n, L;
//物流站坐标与服务范围
int x[2005], a[2005];

int solve() {
    //当前未覆盖的最左侧的居民点
    int r = 0;
    //物流站数量
    int num = 0;
    while (r <= L) {
        //寻找下一个物流站选址
        int nex = -1;
        for (int i = 0; i < n; i++) {
            if (x[i] - a[i] <= r and r <= x[i] + a[i]) {
                if (nex == -1 or x[nex] + a[nex] < x[i] + a[i]) {
                    nex = i;
                }
            }
        }
        //如果没有任何物流站可以覆盖坐标r处的居民点，返回-1
        if (nex == -1)return -1;
        //更新r和num
        r = x[nex] + a[nex] + 1;
        num++;
    }
    return num;
}

int main() {
    //输入
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> a[i];
    }
    //求解并输出
    cout << solve() << endl;
    return 0;
}