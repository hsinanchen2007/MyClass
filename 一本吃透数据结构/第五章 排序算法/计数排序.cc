/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w37vh6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) void CountingSort(int n, int *a)为 计数排序 的实现，代表对a[]数组进行升序排序。
(2) 利用memset初始化 计数器数组 cnt；
(3) 遍历原数组中的每个元素；
(4) 相应数 的 计数器 增加1；
(5) 栈顶指针指向空栈；
(6) 如果 cnt[i] 为零，则结束循环，否则进入 (7);
(7) 将 i 放入原数组；
(8) 计数器减一；
(9) 当原数组个数 等于 n 跳出循环。

*/

#include <stdio.h>
#include <string.h>

#define maxn 1000001
#define maxk 100001

int a[maxn];
int cnt[maxk]; 

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

void CountingSort(int n, int *a) {       // (1)
    int i, top; 
    memset(cnt, 0, sizeof(cnt));         // (2) 
    for(i = 0; i < n; ++i) {             // (3)
        ++cnt[ a[i] ];                   // (4)
    }
    top = 0;                             // (5)
    for(i = 0; i < maxk; ++i) {
        while(cnt[i]) {                  // (6)
            a[top++] = i;                // (7)
            --cnt[i];                    // (8)
        }
        if(top == n) {                   // (9)
            break;
        }
    }
} 

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        CountingSort(n, a);
        Output(n, a);
    }
    return 0;
} 
