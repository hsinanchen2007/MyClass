#include <bits/stdc++.h>
using namespace std;

int n;
//f[i]:以第i道菜为结束时，可以取到的最大美味度之和
long long a[100005], f[100005];

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //求解并输出
    f[0] = max(a[0], (long long)0);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        f[i] = max(a[i], f[i - 1] + a[i]);
        if (f[i] > ans)ans = f[i];
    }
    cout << ans << endl;
    return 0;
}