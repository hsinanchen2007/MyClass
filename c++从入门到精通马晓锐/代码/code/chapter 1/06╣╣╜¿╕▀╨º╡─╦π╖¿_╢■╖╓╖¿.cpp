#include<iostream>
using namespace std;
const int maxn = 100005;
int m;
long long c[maxn];
long long count(long long n)
{
    return n*n*n+n*n+n+1;
}
int main()
{
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> c[i];
    }

    for(int i=0;i<m;i++){
        long long L=0, R=1000000, ans;
      	
      	// 二分法
        while(L<=R){
            long long mid = (L+R)/2;
            if(count(mid)<=c[i]){
                ans = mid; // 记录答案，后来肯定比原来更好
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        cout << ans;
        if(i<m-1) cout << " ";
        else cout << endl;
    }
    return 0;
}