#include<iostream>
#include<algorithm>
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
  	
  	// 调用 sort 函数
    sort(arr, arr + n);

    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}