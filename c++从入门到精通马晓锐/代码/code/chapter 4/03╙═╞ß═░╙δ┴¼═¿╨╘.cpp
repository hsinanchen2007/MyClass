#include <bits/stdc++.h>
using namespace std;

//像素图的颜色值以及边长
int c[1005][1005], n, m;
//访问标记
bool vis[1005][1005];

//算法核心函数，试图将第 x 行第 y 列的像素标记为颜色 color 的连通块
void drop_color(int x, int y, int color) {
    //如果当前点已经被访问过，那么不必再次访问
    if (vis[x][y])return;
    if (x<0 or x >= n or y<0 or y >= m)return;
    if (c[x][y] != color)return;
    vis[x][y] = true;
    drop_color(x - 1, y, color);
    drop_color(x + 1, y, color);
    drop_color(x, y - 1, color);
    drop_color(x, y + 1, color);
}

int main() {
    //输入
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    //求解
    drop_color(x, y, c[x][y]);
    //输出
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ".!"[vis[i][j]] << " \n"[j == m - 1];
        }
    }
    return 0;
}