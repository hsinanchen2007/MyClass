#include <bits/stdc++.h>
using namespace std;

//一个足够大的数，表示“正无穷”
int inf = 100000;
//题目中的变量
int n, s, a[25];

//搜索算法核心函数
int solve(int i, int sum, int num) {
    if (i == n) {
    //已经考虑过所有纸币
        if (sum == s)return num;
        else return inf;
    } else {
    //递归地考虑剩余的其他纸币
        return min(
            solve(i + 1, sum + a[i], num + 1),
            solve(i + 1, sum, num)
        );
    }
}

int main() {
    //输入
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //求解并输出
    cout << solve(0, 0, 0) << endl;
    return 0;
}