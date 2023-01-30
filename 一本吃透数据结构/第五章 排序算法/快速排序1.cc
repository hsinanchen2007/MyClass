/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w30055/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) 随机选择一个基准；
(2) pivox 代表基准值；
(3) 将基准和最左边的值交换；
(4) i 和 j 是两个同步指针，都从 l+1 开始；j−1 以后的数都是大于等于 基准值 的；
(5) 开始遍历整个排序区间，i 一定比 j 走的快，当 i 到达最右边的位置时，遍历结束；
(6) 如果比基准值小的，交换 a[i] 和 a[j]，并且自增 j ；
(7) 每次遍历 i 都需要自增；
(8) 第 j 个元素以后都是不比基准值小的元素 ；

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
    int i, j, pivox; 
    int idx = l + rand() % (r - l + 1);        // (1) 
    pivox = a[idx];                            // (2) 
    Swap(&a[l], &a[idx]);                      // (3) 
    i = j = l + 1;                             // (4) 
                                               // 
    while( i <= r ) {                          // (5) 
        if(a[i] < pivox) {                     // (6) 
            Swap(&a[i], &a[j]);                
            ++j;                               
        }
        ++i;                                   // (7) 
    }
    Swap(&a[l], &a[j-1]);                      // (8) 
    return j-1;
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

