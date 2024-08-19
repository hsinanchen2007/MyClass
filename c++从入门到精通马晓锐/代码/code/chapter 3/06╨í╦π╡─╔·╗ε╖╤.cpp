#include <bits/stdc++.h>
using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(0, 1000000);

int n, x, a[100005];
//求数组中[l,r)范围内的第x个（从0开始）数
int nth_number(int l, int r, int x) {
    //检验这段数组中所有的数是否都相等
    bool same = true;
    for (int k = l; k < r; k++) {
        if (a[k] != a[l])same = false;
    }
    //如果这段数组中所有的数都相等，直接返回答案
    if (same)return a[l];
    //随机选取一个支点变量
    int pivot = a[l + distribution(generator) % (r - l)];
    //用类似快速排序的过程，把小于支点变量的放在左边，大于或等于支点变量的放在右边
    int i = l, j = r - 1, k = r - 1;
    while (true) {
        while (a[i] < pivot)i++;
        while (a[j] >= pivot)j--;
        if (i < j)swap(a[i], a[j]);
        else break;
    }
    //在右侧部分中，把等于支点变量的放在左边，大于支点变量的放在右边
    j = i;
    while (true) {
        while (a[j] == pivot)j++;
        while (a[k] > pivot)k--;
        if (j < k)swap(a[j], a[k]);
        else break;
    }
    //根据各部分的数量缩小范围
    if (i - l > x)return nth_number(l, i, x);
    else if (j - l > x)return nth_number(i, j, x - (i - l));
    else return nth_number(j, r, x - (j - l));
}

int main() {
    //输入
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //求解并输出
    cout << nth_number(0, n, x) << endl;
    return 0;
}