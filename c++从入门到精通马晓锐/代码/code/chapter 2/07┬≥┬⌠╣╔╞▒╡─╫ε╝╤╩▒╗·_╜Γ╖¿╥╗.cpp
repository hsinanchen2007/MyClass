#include <bits/stdc++.h>
using namespace std;

//题目中的变量
int n, price[100005];

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    //求解
    int maxprofit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (price[j] - price[i] > maxprofit)maxprofit = price[j] - price[i];
        }
    }
    //输出
    cout << maxprofit << endl;
    return 0;
}