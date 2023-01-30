/*

作者：英雄哪里出来
链接：https://leetcode.cn/leetbook/read/data-structure-all-in-one/w3di97/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

(1) 申请一个辅助数组，用于对原数组进行归并计算；
(2) 只有一个元素，或者没有元素的情况，则不需要排序；
(3) 将数组分为 [l,mid] 和 [mid+1,r] 两部分；
(4) 递归排序 [l,mid] 部分；
(5) 递归排序 [mid+1,r] 部分；
(6) 将需要排序的数组缓存到tmp中，用p作为游标；
(7) 初始化两个数组的指针；
(8) 当两个指针都没有到结尾，则继续迭代；
(9) 只剩下右边的数组，直接排；
(10) 只剩下走右边的数组，直接排；
(11) 取小的那个先进tmp数组；
(12) 别忘了将排序好的数据拷贝回原数组；
(13) 别忘了释放临时数据，否则就内存泄漏了！！！

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

void MergeSort(int *nums, int l, int r) {
    int i, mid, p, lp, rp;
    int *tmp = (int *)malloc( (r-l+1) * sizeof(int) );    // (1)  
    if(l >= r) {
        return ;                                          // (2) 
    }
    mid = (l + r) >> 1;                                   // (3) 
    MergeSort(nums, l, mid);                              // (4) 
    MergeSort(nums, mid+1, r);                            // (5) 
    p = 0;                                                // (6) 
    lp = l, rp = mid+1;                                   // (7) 
    while(lp <= mid || rp <= r) {                         // (8) 
        if(lp > mid) {
            tmp[p++] = nums[rp++];                        // (9) 
        }else if(rp > r) {
            tmp[p++] = nums[lp++];                        // (10) 
        }else {
            if(nums[lp] <= nums[rp]) {                    // (11) 
                tmp[p++] = nums[lp++];
            }else {
                tmp[p++] = nums[rp++];
            }
        }
    }
    for(i = 0; i < r-l+1; ++i) {
        nums[l+i] = tmp[i];                               // (12) 
    } 
    free(tmp);                                            // (13) 
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Input(n, a);
        MergeSort(a, 0, n-1);
        Output(n, a);
    }
    return 0;
} 
