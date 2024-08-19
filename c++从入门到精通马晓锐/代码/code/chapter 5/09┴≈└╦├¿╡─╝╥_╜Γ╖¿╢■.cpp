#include <bits/stdc++.h>
using namespace std;

//网格边长
int n;
//网格的杂物情况
int block[15][15];
//f[i][s]表示第i行采用安置方式s时，前i行可以容纳的最多小猫咪数量
int f[15][1 << 15];
//p[i][s]表示使f[i][s]取得最大值的前一行安置方式
int p[15][1 << 15];
//每一种安置方式容纳的小猫咪数量
int N[1 << 15];
//不考虑杂物网格时所有合理的安置方式
vector<int> S;
//对于每个安置方式可以进行转移的安置方式集合
vector<int> T[1 << 15];

//判断这一行是否有小猫咪相邻
bool check(int state) {
    int last = -2;
    for (int i = 0; i < n; i++) {
        if (state & 1) {
            if (i - last < 2)return false;
            last = i;
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
//计算每个安置方式包含的小猫咪数量（二进制中1的个数）
void calculate_N() {
    for (auto s : S) {
        N[s] = __builtin_popcount(s);
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
//动态规划
void dp() {
    for (int i = 0; i < n; i++) {
        //将本行的杂物编码为一个整数，注意顺序
        int b = 0;
        for (int j = n - 1; j >= 0; j--) {
            b = b * 2 + block[i][j];
        }
        if (i == 0) {
            //第一行单独考虑
            for (auto s : S) {
                if ((s & b) == 0)f[i][s] = N[s];
            }
        } else {
            //从第二行开始，每一行根据上一行的状态进行转移
            for (auto s : S) {
                if ((s & b) != 0)continue; //本行该安置方式与杂物网格冲突
                for (auto t : T[s]) {
                    if (f[i - 1][t] + N[s] > f[i][s]) {
                        f[i][s] = f[i - 1][t] + N[s];
                        p[i][s] = t;
                    }
                }
            }
        }
    }
}
//输出
void output() {
    //计算最后一行的最优安置方式
    int state = 0;
    for (auto s : S) {
        if (f[n - 1][s] > f[n - 1][state])state = s;
    }
    //倒序计算每一行的最优安置方式
    for (int i = n - 1; i >= 0; i--) {
        //将本行的安置方式填充到block数组中，用2表示小猫咪
        int temp = state;
        for (int j = 0; j < n; j++) {
            if (temp & 1)block[i][j] = 2;
            temp >>= 1;
        }
        state = p[i][state];
    }
    //输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //block数组中，0表示没有安置小猫咪，1表示杂物，2表示安置了小猫咪
            cout << ".#c"[block[i][j]] << " \n"[j == n - 1];
        }
    }
}


int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string temp;
            cin >> temp;
            //block数组中，0表示可以安置小猫咪，1表示有杂物不能安置小猫咪
            if (temp == "#")block[i][j] = 1;
        }
    }
    //计算得到所有无小猫咪相邻的状态
    calculate_S();
    //计算每个安置方式包含的小猫咪数量（二进制中1的个数）
    calculate_N();
    //计算对于每个安置方式可以进行转移的安置方式集合
    calculate_T();
    //动态规划
    dp();
    //输出
    output();
    return 0;
}