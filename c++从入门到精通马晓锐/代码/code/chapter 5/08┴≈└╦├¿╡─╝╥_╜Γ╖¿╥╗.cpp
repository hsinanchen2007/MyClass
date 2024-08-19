#include <bits/stdc++.h>
using namespace std;

//网格边长
int n;
//不考虑杂物网格时所有合理的安置方式
vector<int> S;
//对于每个安置方式可以进行转移的安置方式集合
vector<int> T[1 << 15];

//判断这一行是否有小猫咪相邻
bool check(int state) {
    while(state > 0) {
        if(state & 3 == 3) {
            return false;
        }
        state >>= 1;
    }
    return true;
}
//计算得到所有无小猫咪相邻的状态
void calculate_S() {
    for (int i = 0; i < (1 << n); i++) {
        if (check(i))S.push_back(i);
    }
}
//计算对于每个安置方式可以进行转移的安置方式集合
void calculate_T() {
    for (auto s : S) {
        for (auto t : S) {
            if ((s & t) == 0)T[s].push_back(t);
        }
    }
}

int main() {
    //输入
    cin >> n;
    //计算得到所有无小猫咪相邻的状态
    calculate_S();
    //计算对于每个安置方式可以进行转移的安置方式集合
    calculate_T();
    //输出所有状态转移的次数
    int num = 0;
    for (auto s : S)num += T[s].size();
    cout << num*n << endl;
    return 0;
}