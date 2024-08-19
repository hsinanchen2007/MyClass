#include <bits/stdc++.h>
using namespace std;

//拼图碎片的种类数、要拼出形状的长度
int n, L;
//每种拼图碎片的长度
int l[1005];
//拼好长度为 i 的部分的方案数
long long f[1005];
//1000000007
const long long mod = 1e9 + 7;

int main() {
    //输入
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    //求解
    f[0] = 1;
    for (int i = 1; i <= L; i++) {
        //枚举最后一块拼图碎片，利用前面状态的计算结果进行计算
        for (int j = 0; j < n; j++) {
            if (i - l[j] >= 0) {
                f[i] = (f[i] + f[i - l[j]]) % mod;
            }
        }
    }
    //输出
    cout << f[L] << endl;
    return 0;
}