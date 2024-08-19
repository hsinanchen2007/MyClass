#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100000+5;
int n;
int a[maxn];
int tmp[maxn];// tmp数组用来存放归并中的临时数据
void mergeSort(int L,int R){
    if(R-L<=1)return;
    int mid=(L+R)/2;
    mergeSort(L,mid);
    mergeSort(mid,R);
    int p1=L,p2=mid,tot=L;
    while(p1<mid or p2<R){
        if(p2==R)temp[tot++]=a[p1++];
        else if(p1==mid)temp[tot++]=a[p2++];
        else if(a[p1]<a[p2])temp[tot++]=a[p1++];
        else temp[tot++]=a[p2++];
    }
    for(int i=L;i<R;i++)a[i]=temp[i];
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  
    mergeSort(0, n-1);
  	
  	for(int i=0;i<n;i++){
      	cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}