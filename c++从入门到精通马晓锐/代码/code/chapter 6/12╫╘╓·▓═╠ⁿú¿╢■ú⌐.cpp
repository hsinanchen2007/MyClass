#include <bits/stdc++.h>
using namespace std;

//菜品的数量
int n;
//菜品的美味度（及相关临时变量）
int a[100005], a_temp[100005];
//index数组用来记录位置i处菜品原本的编号
int index[100005], index_temp[100005];
//low[i]表示有多少菜品可以作为第i道菜品的前菜
int low[100005];
//high[i]表示有多少菜品可以作为第i道菜品的甜点
int high[100005];

void mergeSort(int L, int R) {
    if (R - L <= 1)return;
    int mid = (L + R) / 2;
    mergeSort(L, mid);
    mergeSort(mid, R);
    int p1 = L, p2 = mid, tot = L;
    while (p1 < mid or p2 < R) {
        //判断接下来要对哪个数字归并
        int merge_left = 0;
        if (p2 == R)merge_left = 1;
        else if (p1 == mid)merge_left = 0;
        else if (a[p1] <= a[p2])merge_left = 1;
        else merge_left = 0;
        if (merge_left) {//归并左侧的数字
            index_temp[tot] = index[p1];
            a_temp[tot] = a[p1];
            high[index[p1]] += R - p2;
            tot++, p1++;
        } else {//归并右侧的数字
            index_temp[tot] = index[p2];
            a_temp[tot] = a[p2];
            low[index[p2]] += p1 - L;
            tot++, p2++;
        }
    }
    //将临时变量数组中的数据放回原数组
    for (int i = L; i < R; i++)a[i] = a_temp[i];
    for (int i = L; i < R; i++)index[i] = index_temp[i];
}

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        index[i] = i;
    }
    //求解
    mergeSort(0, n);
    long long ans = 0;//注意答案用int存不下哦
    for (int i = 0; i < n; i++) {
        ans += (long long)low[i] * high[i];
    }
    //输出
    cout << ans << endl;
    return 0;
}