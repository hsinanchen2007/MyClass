/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3w8e1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) void InsertSort(int n, int *a)为 插入排序 的实现，代表对a[]数组进行升序排序。
(2) 此时a[i]前面的 i-1个数都认为是排好序的，令x = a[i]；
(3) 逆序的枚举所有的已经排好序的数；
(4) 如果枚举到的数a[j]比需要插入的数x大，则当前数往后挪一个位置；
(5) 执行挪位置的 O(1) 操作；
(6) 否则，跳出循环；
(7) 将x插入到合适位置；

*/

#include <stdio.h>

int a[1010];

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

void InsertSort(int n, int *a) {       // (1)
    int i, j; 
    for(i = 1; i < n; ++i) {
        int x = a[i];                  // (2)
        for(j = i-1; j >= 0; --j) {    // (3)
            if(x <= a[j]) {            // (4)
                a[j+1] = a[j];         // (5)
            }else
                break;                 // (6)
        }
        a[j+1] = x;                    // (7)
    }
} 

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        InsertSort(n, a);
        Output(n, a);
    }
    return 0;
} 

