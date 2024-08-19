#include<iostream>
#include<cstdlib> // 随机函数头文件
#include<ctime> // 获取时间设置随机种子
using namespace std;
const int maxn = 100005;
int n;
int arr[maxn];
void quick_sort(int L,int R)
{
    if(L>=R){
        return;
    }
    // 随机选出基准数
    int idx = (rand()%(R-L+1))+ L;
    int base = arr[idx];

    // 把基准数放到最左边，简化后续逻辑
    swap(arr[idx],arr[L]);
    int i=L,j=R;
    while(i<j){
        // 找到一个右侧，比基准数小的数字
        while(arr[j] >= base && i<j)
            j--;
        // 找到一个左侧，比基准数大的数字
        while(arr[i] <= base && i<j)
            i++;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    // i 和 j 相遇的数字一定 小于等于基准数
    // 进行交换，基准数归位
    swap(arr[L],arr[j]);
    quick_sort(L,i-1);
    quick_sort(i+1,R);
}
int main()
{
    srand((unsigned)time(NULL));
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quick_sort(0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}