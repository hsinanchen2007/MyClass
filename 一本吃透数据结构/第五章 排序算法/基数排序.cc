/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3lmf2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) 排序数组的元素最大个数；
(2) 排序元素的数字的最大位数；
(3) 排序元素的进制，这里为 十进制；
(4) PowOfBase[i]代表BASE的i次幂；
(5) RadixBucket[i][]代表第 i 个队列；
(6) RadixBucketTop[i]代表第 i 个队列的尾指针；
(7) 初始化BASE的i次幂；
(8) 计算value的pos位的值；
(9) void RadixSort(int n, int *a)为 基数排序 的实现，代表对a[]数组进行升序排序；
(10) 进行MAXT轮迭代；
(11) 迭代前清空队列，只需要将队列尾指针置零即可；
(12) 入队操作；
(13) 将队列中的元素按顺序塞回原数组；

*/

#include <stdio.h>
#include <string.h>

const int MAXN = 100005;          // (1) 
const int MAXT = 8;               // (2) 
const int BASE = 10;              // (3) 
int PowOfBase[MAXT];              // (4) 
int RadixBucket[BASE][MAXN];      // (5) 
int RadixBucketTop[BASE];         // (6) 


void InitPowOfBase() {
    int i;
    PowOfBase[0] = 1;
    for(i = 1; i < MAXT; ++i) {
        PowOfBase[i] = PowOfBase[i-1] * BASE;   // (7)
    }
}

void Input(int n, int *a) {
    int i;
    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void Output(int n, int *a) {
    int i; 
    for(i = 0; i < n; ++i) {
        if(i)
            printf(" ");
        printf("%d", a[i]);
    }
    puts("");
}

int getRadix(int value, int pos) {
    return value / PowOfBase[pos] % BASE;        // (8)
}

void RadixSort(int n, int *a) {                  // (9)
    int i, j, top = 0, pos = 0;
    while (pos < MAXT) {                         // (10)
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));      // (11)
        for(i = 0; i < n; ++i) {
            int rdx = getRadix(a[i], pos);
            RadixBucket[ rdx ][ RadixBucketTop[rdx]++ ] = a[i]; // (12)
        }
        top = 0;
        for(i = 0; i < BASE; ++i) {
            for(j = 0; j < RadixBucketTop[i]; ++j) {
                a[top++] = RadixBucket[i][j];                   // (13)
            }
        }
        ++pos; 
    }
}

int a[MAXN];

int main() {
    int n;
    InitPowOfBase();
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        RadixSort(n, a);
        Output(n, a);
    }
    return 0;
} 
/*
15
3221 1 10 9680 577 9420 7 5622 4793 2030 3138 82 2599 743 4127
*/
