#include <bits/stdc++.h>
using namespace std;

//数独网格，其中0表示空位
int a[15][15];

//判断这个空位能否填数
bool canFill(int x, int y, int n) {
    //查找当前行是否有重复数字
    for (int i = 1; i <= 9; i++) {
        if (a[x][i] == n)return false;
    }
    //查找当前列是否有重复数字
    for (int i = 1; i <= 9; i++) {
        if (a[i][y] == n)return false;
    }
    //查找当前3*3网格中是否有重复数字
    int px, py;
    if (x <= 3)px = 1;
    else if (x <= 6)px = 4;
    else px = 7;
    if (y <= 3)py = 1;
    else if (y <= 6)py = 4;
    else py = 7;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (a[px + i][py + j] == n)return false;
        }
    }
    //按照游戏规则，当前位置可以填数字n
    return true;
}

//用深度优先搜索算法尝试填数
bool dfs() {
    //枚举每一个网格位置
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            //如果已经填过数字，跳过
            if (a[i][j] != 0)continue;
            //找到第一个空位，枚举1~9每一个数字，尝试填入
            for (int n = 1; n <= 9; n++) {
                //如果可以填该数字
                if (canFill(i, j, n)) {
                    //填写该数字，更新网格状态
                    a[i][j] = n;
                    //把网格交给后续的机器人，如果后续的机器人能够填好，返回true
                    if (dfs())return true;
                    //如果后续的机器人不能填好，撤回刚刚填入的数字，以便尝试填入其他数字
                    a[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}
int main() {
    //输入
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> a[i][j];
        }
    }
    //求解
    dfs();
    //输出
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}