#include<iostream>
#include<algorithm>
using namespace std ;

int main()
{   
    vector<int> v {10, 20, 30};
    
    for_each (v.begin(), v.end(), 
        [] ( int &x ) { x *= 2 ; } );
    
    auto print = [](int x) {cout << x << ' ' ;};
    
    for_each (v.begin(), v.end(), print);
    
    return 0 ;
}



#include<iostream>
#include<algorithm>
using namespace std ;

int main()
{   
    vector<int> v {10, 20, 30};
    
    int res = count_if(v.begin(), v.end(), 
        [](int x) {return x < 10; });     
    
    cout << res;
    
    return 0 ;
}



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main()
{   
    vector<int> v {100, 20, 4, 200, 1};
    
    auto it = find_if(v.begin(), v.end(), 
        [](int x) {return x < 10;});     
    
    cout << *it;
    
    return 0 ;
}



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main()
{   
    vector<int> v {100, 20, 4, 200, 1};
    
    int res = accumulate(v.begin(), v.end(),0);
    cout << res << '\n';
    
    res = accumulate(v.begin(), v.end(), 1,
        [](int x, int y){return x*y;});
    cout << res;
    
    return 0 ;
}




