#include <bits/stdc++.h>
using namespace std;

//行数和列数
int n, m;
//网格，1~8表示数字，9表示未知格子或地雷
int board[15][15];
//网格，1表示有地雷，0表示未知，-1表示没有地雷
int mine[15][15];
//标记访问过的位置
int vis[15][15];
//路径的坐标
vector<int> path_x, path_y;

//检验x,y是否超出边界
bool in_range(int x, int y) {
    return x >= 0 and x<n and y >= 0 and y < m;
}
//检验当前mine数组中的地雷排布是否合理
bool check_valid() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] >= 0 and board[x][y] < 9) {
                //计算四周8个格子的地雷数量与未知格子数量
                int mine_num = 0, unknow_num = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (in_range(x + i, y + j) and board[x + i][y + j] == 9) {
                            if (mine[x + i][y + j] == 1)mine_num++;
                            else if (mine[x + i][y + j] == 0)unknow_num++;
                        }
                    }
                }
                if (board[x][y]<mine_num or board[x][y]>mine_num + unknow_num) {
                    return false;
                }
            }
        }
    }
    return true;
}
//检验一条路径是否为“关键路径”
bool check_path() {
    bool flag = true;
    int all_state = 1 << path_x.size();
    for (int s = 0; s < all_state; s++) {
        int temp = s;
        for (int i = 0; i < (int)path_x.size(); i++) {
            mine[path_x[i]][path_y[i]] = temp % 2 == 1 ? 1 : -1;
            temp /= 2;
        }
        //如果存在一种合理的地雷排布，那么这条路径不是“关键路径”
        if (check_valid()) {
            flag = false;
            break;
        }
    }
    //清空mine数组，避免与后续计算冲突
    for (int i = 0; i < (int)path_x.size(); i++) {
        mine[path_x[i]][path_y[i]] = 0;
    }
    return flag;
}
//查找是否存在“关键路径”，当前已走到第x行第y列，最大搜索深度为max_depth
bool search_path(int x, int y, int max_depth) {
    //如果路径长度达到最大深度，判断该路径是否为“关键路径”
    if ((int)path_x.size() == max_depth)return check_path();
    //枚举相邻的位置，扩展路径
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            //找到一个没有访问过的未知格子
            if (in_range(x + i, y + j) and board[x + i][y + j] == 9
                    and !vis[x + i][y + j] and mine[x + i][y + j] == 0) {
                //将该点加入队列，并继续搜索
                vis[x + i][y + j] = 1;
                path_x.push_back(x + i);
                path_y.push_back(y + j);
                if (search_path(x + i, y + j, max_depth))return true;
                //加入该点后找不到“关键路径”，将其删除
                path_x.pop_back();
                path_y.pop_back();
                vis[x + i][y + j] = 0;
            }
        }
    }
    //找不到“关键路径”
    return false;
}
//判断第x行第y列是否有地雷
int solve_grid(int x, int y) {
    if (mine[x][y] != 0)return mine[x][y];
    //深度max_depth从1开始增加，至多为10
    for (int max_depth = 1; max_depth < 11; max_depth++) {
        //清空vis数组与路径数组
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
        path_x.clear();
        path_y.clear();
        //开始求解
        vis[x][y] = 1;
        //假设第x行第y列是地雷，如果找到“关键路径”，那么不是地雷
        mine[x][y] = 1;
        if (search_path(x, y, max_depth)) {
            mine[x][y] = 0;
            return -1;
        }
        //假设第x行第y列不是地雷，如果找到“关键路径”，那么是地雷
        mine[x][y] = -1;
        if (search_path(x, y, max_depth)) {
            mine[x][y] = 0;
            return 1;
        }
        mine[x][y] = 0;
    }
    //无法判断
    return 0;
}

int main() {
    //输入
    cin >> n >> m;
    string s;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> s;
            if (s == "?")board[x][y] = 9, mine[x][y] = 0;
            else if (s == "*")board[x][y] = 9, mine[x][y] = 1;
            else board[x][y] = s[0] - '0', mine[x][y] = -1;
        }
    }
    int x, y;
    cin >> x >> y;
    //计算并输出
    cout << solve_grid(x, y) << endl;
    return 0;
}