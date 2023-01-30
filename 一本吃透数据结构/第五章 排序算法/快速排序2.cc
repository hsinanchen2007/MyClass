/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w30055/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) 随机选择一个基准 ；
(2) 将基准和最左边的值交换 ；
(3) 初始区间 [l,r]；
(4) 这里的 x 是一开始随机出来那个基准值 ；
(5) 从右往左找，第一个满足a[j] <= x基准值 的，退出循环 ；
(6) 如果a[j] <= x基准值 ，则a[j]必须和 x交换，才能满足a[j]在基准值左边；且此时基准值是a[i]，交换完，基准值变成原先的a[j]，且 i 需要自增一次；
(7) 从左往右找，第一个满足a[i] >= x基准值 的，退出循环 ；
(8) 如果a[i] >= x，则a[i]必须和x交换，才能满足a[i]在基准值右边；交换完，基准值又变回为a[i]，继续迭代；

*/

#include <stdio.h>
#include <malloc.h>
 
#define maxn 1000001

int a[maxn];

void Input(int n, int *a) {
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void Output(int n, int *a) {
    for(int i = 0; i < n; ++i) {
        if(i)
            printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int a[], int l, int r){
    int i, j; 
    int idx = l + rand() % (r - l + 1);        // (1) 
    Swap(&a[l], &a[idx]);                      // (2) 
    i = l, j = r;                              // (3) 
    int x = a[i];                              // (4) 
    while(i < j){
        while(i < j && a[j] > x)               // (5) 
            j--;
        if(i < j) 
             Swap(&a[i], &a[j]), ++i;          // (6) 
                                               // 
                                            
        while(i < j && a[i] < x)               // (7) 
            i++;
        if(i < j)
            Swap(&a[i], &a[j]), --j;           // (8) 
    }
    a[i] = x;
    return i;
}
//递归进行划分
void QuickSort(int a[], int l, int r){
    if(l < r){
        int mid = Partition(a, l, r);
        QuickSort(a, l, mid-1);
        QuickSort(a, mid+1, r);
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        QuickSort(a, 0, n-1);
        Output(n, a);
    }
    return 0;
} 

