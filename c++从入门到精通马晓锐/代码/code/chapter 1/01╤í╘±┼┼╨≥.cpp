#include<iostream>
using namespace std;
const int maxn = 100005;
int n;
int arr[maxn];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // 重复找 n-1 次最小的数字
    for(int i=0;i<n-1;i++){
        int idx = i; // 记录目前已知的最小数字的序号
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[idx]){
                idx = j;
            }
        }
        swap(arr[i],arr[idx]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}