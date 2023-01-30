/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3nzp3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) void BubbleSort(int n, int *a)为冒泡排序的实现，代表对a[]数组进行升序排序。
(2) swapped标记本轮迭代下来，是否有元素产生了交换。
(3) 每次冒泡的结果，会执行last的自减，所以待排序的元素会越来越少。
(4) 如果发现两个相邻元素产生逆序，则将它们进行交换。保证右边的元素一定不比左边的小。
(5) swap实现了元素的交换，这里需要用&转换成地址作为传参。
(6) 标记更新。一旦标记更新，则代表进行了交换，所以下次迭代必须继续。

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

void BubbleSort(int n, int *a) {             // (1)
    bool swapped;
    int last = n;
    do {
        swapped = false;                     // (2)
        for(int i = 0; i < last - 1; ++i) {  // (3)
            if(a[i] > a[i+1]) {              // (4)
                Swap(&a[i], &a[i+1]);        // (5)
                swapped = true;              // (6)
            }
        }
        --last;
    }while (swapped);
} 

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        BubbleSort(n, a);
        Output(n, a);
    }
    return 0;
} 
