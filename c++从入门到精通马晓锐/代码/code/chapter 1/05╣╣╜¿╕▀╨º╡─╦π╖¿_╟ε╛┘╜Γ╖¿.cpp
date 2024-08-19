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
        long long j = 0;
        while(count(j)<=c[i]){
            j++;
        }
        cout << j-1;
        if(i<m-1) cout << " ";
        else cout << endl;
    }
    return 0;
}