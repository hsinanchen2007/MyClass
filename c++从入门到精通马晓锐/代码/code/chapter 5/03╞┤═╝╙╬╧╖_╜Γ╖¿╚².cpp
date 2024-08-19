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
//用记忆化搜索计算f[i]
long long calculate_f(int i) {
    //如果已经计算过，直接返回答案
    if (f[i] != -1)return f[i];
    else {
        f[i] = 0;
        //枚举最后一块拼图碎片，利用前面状态的计算结果进行计算
        for (int j = 0; j < n; j++) {
            if (i - l[j] >= 0) {
                f[i] = (f[i] + calculate_f(i - l[j])) % mod;
            }
        }
        return f[i];
    }
}

int main() {
    //输入
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    //初始化，-1表示还未计算过
    f[0] = 1;
    for (int i = 1; i <= L; i++)f[i] = -1;
    //求解并输出
    cout << calculate_f(L) << endl;
    return 0;
}