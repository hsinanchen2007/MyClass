/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3iobc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) 每隔gap个数作为一组，gap = n/2, n/4, n/8, ..., 1；
(2) 从第gap个数开始遍历；
(3)−(5) 找到一个需要插入的位置，并且跳出循环；
(6) 第 j 个位置就是这个数需要插入的位置 ；

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

void ShellSort(int n, int a[]){
    int i, j, tmp, gap;
    for(gap = n / 2; gap > 0; gap /= 2) {      // (1)   
        for(i = gap; i < n; ++i) {             // (2)   
            tmp = a[i];
            for(j = i; j >= gap; j -= gap) {   // (3)   
                if(tmp < a[j - gap]) {         // (4)    
                    a[j] = a[j - gap];
                }else {
                    break;                     // (5)  
                }
            }
            a[j] = tmp;                        // (6)  
        }
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        ShellSort(n, a);
        Output(n, a);
    }
    return 0;
} 
