#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
//求区间a[L],a[L+1],...,a[R-1]中能够取到的最大美味度之和
long long max_sum(int L, int R) {
    //如果区间长度只有1，直接得到答案，结束递归
    if (L == R - 1)return max(a[L], (long long)0);
    //以中点为界，切分成左右两部分
    int mid = (L + R) / 2;
    //求出横跨左右两部分的取法中最大的美味度
    long long l_sum = 0, r_sum = 0, sum;
    sum = 0;
    for (int i = mid - 1; i >= L; i--) {
        sum += a[i];
        if (sum > l_sum)l_sum = sum;
    }
    sum = 0;
    for (int i = mid; i < R; i++) {
        sum += a[i];
        if (sum > r_sum)r_sum = sum;
    }
    long long ans = l_sum + r_sum;
    //求出只在左半部分的取法中最大的美味度
    ans = max(ans, max_sum(L, mid));
    //求出只在右半部分的取法中最大的美味度
    ans = max(ans, max_sum(mid, R));
    return ans;
}
int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //求解并输出
    cout << max_sum(0, n) << endl;
    return 0;
}