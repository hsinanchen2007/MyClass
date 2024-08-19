#include <bits/stdc++.h>
using namespace std;

//拼图碎片的种类数、要拼出形状的长度
int n, L;
//每种拼图碎片的长度
int l[1005];
//用深度优先搜索进行求解 length：当前已经拼出的长度
long long solve(int length) {
    if (length > L)return 0;
    else if (length == L)return 1;
    else {
        long long ans = 0;
        //枚举下一块拼图碎片的形状，将其长度加到length中，继续求解
        for (int i = 0; i < n; i++) {
            ans += solve(length + l[i]);
        }
        return ans;
    }
}

int main() {
    //输入
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    //求解并输出
    cout << solve(0) << endl;
    return 0;
}