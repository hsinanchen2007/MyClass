/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3v6rm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) void SelectionSort(int n, int *a)为选择排序的实现，代表对a[]数组进行升序排序。
(2) 从首元素个元素开始进行 n−1 次跌迭代。
(3) 首先，记录min代表当前第 i 轮迭代的最小元素的下标为 i。
(4) 然后，迭代枚举第 i+1 个元素到 最后的元素。
(5) 选择一个最小的元素，并且存储下标到min中。
(6) 将 第 i 个元素 和 最小的元素 进行交换。

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

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSort(int n, int *a) {  // (1)
    int i, j;
    for(i = 0; i < n - 1; ++i) {     // (2)
        int min = i;                 // (3)
        for(j = i+1; j < n; ++j) {   // (4)
            if(a[j] < a[min]) {
                min = j;             // (5)
            }
        }
        Swap(&a[i], &a[min]);        // (6) 
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        SelectionSort(n, a);
        Output(n, a);
    }
    return 0;
} 
