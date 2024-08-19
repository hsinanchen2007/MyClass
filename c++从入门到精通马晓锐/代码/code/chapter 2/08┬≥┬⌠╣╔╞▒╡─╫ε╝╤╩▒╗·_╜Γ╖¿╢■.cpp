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
    int maxprofit = 0, minprice = 10000;
    for (int i = 0; i < n; i++) {
        if (price[i] - minprice > maxprofit) maxprofit = price[i] - minprice;
        if (price[i] < minprice) minprice = price[i];//维护一个最小值
    }
    //输出
    cout << maxprofit << endl;
    return 0;
}