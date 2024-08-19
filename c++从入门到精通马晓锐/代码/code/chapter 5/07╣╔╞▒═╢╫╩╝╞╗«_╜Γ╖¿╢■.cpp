#include <bits/stdc++.h>
using namespace std;

//股票交易日的天数、最大交易次数
int n, q;
//每天的股票价格
double p[2005];
//m[i][j]表示直到第i天结束为止恰好进行了j次交易能够获得的最大收益
double m[2005][2005];
//s[i][j]表示直到第i天结束为止恰好进行了j次交易能够获得的最多股票
double s[2005][2005];

double max_profit() {
    //最开始只有一元钱
    m[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= q; j++) {
            double profit;
            //s[i-1][j]->s[i][j] 第i天不买不卖
            profit = s[i - 1][j];
            if (profit > s[i][j])s[i][j] = profit;
            //s[i-1][j-1]->m[i][j] 第i天卖出
            if (j - 1 >= 0) {
                profit = s[i - 1][j - 1] * p[i];
                if (profit > m[i][j])m[i][j] = profit;
            }
            //m[i-1][j-1]->s[i][j] 第i天买入
            if (j - 1 >= 0) {
                profit = m[i - 1][j - 1] / p[i];
                if (profit > s[i][j])s[i][j] = profit;
            }
            //m[i-1][j]->m[i][j] 第i天不买不卖
            profit = m[i - 1][j];
            if (profit > m[i][j])m[i][j] = profit;
        }
    }
    //计算最终答案
    double ans = 0;
    for (int j = 0; j <= q; j++)ans = max(ans, m[n][j]);
    return ans;
}

int main() {
    //输入
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    //求解并按照指定格式输出
    cout << fixed << setprecision(3) << max_profit() << endl;
    return 0;
}