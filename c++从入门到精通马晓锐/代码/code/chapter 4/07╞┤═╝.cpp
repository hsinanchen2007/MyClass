#include <bits/stdc++.h>
using namespace std;

//拼图游戏状态
struct Board {
    //存储每个网格中的拼图碎片（1~8表示拼图碎片，0表示空余网格）
    int board[3][3];
    //将当前状态编码为一个整数
    int encode() {
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans = ans * 9 + board[i][j];
            }
        }
        return ans;
    }
    //判断当前的拼图是否已经复原
    bool win() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != i * 3 + j)return false;
            }
        }
        return true;
    }
};
//队列，用于广度优先搜索
queue<Board> q;
//unordered_map用于判断一个状态是否曾被遍历过，以及记录每个状态被遍历时的最小步数
unordered_map<int, int> step;
//四个移动方向
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
//广度优先搜索
int bfs(Board b) {
    //处理初始状态
    q.push(b);
    step[b.encode()] = 0;
    //开始广度优先搜索
    while (!q.empty()) {
        //取出队首的状态
        b = q.front();
        q.pop();
        //如果拼图已经复原，直接结束搜索
        if (b.win())return step[b.encode()];
        //当前状态所需的最小步数
        int now_step = step[b.encode()];
        //找到空余网格的位置
        for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)if (b.board[i][j] == 0) {
            //枚举空余网格的上下左右四个方向
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x<0 or x>2 or y<0 or y>2)continue;
                //把对应方向的拼图碎片移动过来，得到后续状态
                swap(b.board[i][j], b.board[x][y]);
                //如果后续状态没有被遍历过，放入队列中
                if (!step.count(b.encode())) {
                    q.push(b);
                    step[b.encode()] = now_step + 1;
                }
                //复原状态
                swap(b.board[i][j], b.board[x][y]);
            }
        }
    }
    //如果直到队列清空拼图都未复原，那么这个拼图游戏是无法复原的
    return -1;
}

int main() {
    //输入
    Board b;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b.board[i][j];
        }
    }
    //计算并输出
    cout << bfs(b) << endl;
    return 0;
}