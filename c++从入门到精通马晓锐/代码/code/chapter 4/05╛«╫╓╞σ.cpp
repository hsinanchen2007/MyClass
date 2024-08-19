#include <bits/stdc++.h>
using namespace std;

//记忆化数组
int memory[20000];
//棋盘状态
int board[3][3];

//编码函数，将棋盘状态编码为整数
int encode() {
    //编码为三进制数
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans = ans * 3 + board[i][j];
        }
    }
    return ans;
}

//判断游戏是否结束
//-1:游戏还未结束
//0:游戏以平局结束
//1:先手已获胜
//2:后手已获胜
int game_end() {
    //枚举每一位玩家
    for (int player = 1; player <= 2; player++) {
        //查找该玩家是否存在三点一线
        for (int i = 0; i < 3; i++) {
            if (
                board[i][0] == player
                and board[i][1] == player
                and board[i][2] == player
            )return player;
            if (
                board[0][i] == player
                and board[1][i] == player
                and board[2][i] == player
            )return player;
        }
        if (
            board[0][0] == player
            and board[1][1] == player
            and board[2][2] == player
        )return player;
        if (
            board[0][2] == player
            and board[1][1] == player
            and board[2][0] == player
        )return player;
    }
    //没有出现三点一线，检验是否还有空位
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)return -1;
        }
    }
    //没有出现三点一线，且没有空位，游戏以平局结束
    return 0;
}

//求解当前状态下的胜者
int solve(int player) {
    //在记忆化数组中查找计算结果
    if (memory[encode()] != 0)return memory[encode()];
    //检验游戏是否已经结束
    if (game_end() != -1)return game_end();
    int another_player = 3 - player;
    int result = another_player;
    //枚举落子位置
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                //尝试在此处落子
                board[i][j] = player;
                //递归地对另一玩家的状态进行求解
                int next_result = solve(another_player);
                if (next_result == player) {
                    //如果能够令对方面对必败状态，那么此时是必胜状态
                    result = player;
                } else if (next_result == 0 and result == another_player) {
                    //如果不能令对方面对必败状态，那么尽可能争取平局
                    result = 0;
                }
                //撤回此处的落子，以便尝试其他落子方式
                board[i][j] = 0;
            }
        }
    }
    //将当前状态的计算结果存储到记忆化数组中
    memory[encode()] = result;
    return result;
}

int main() {
    //输入
    int player;
    cin >> player;
    int another_player = 3 - player;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            if (s == ".")board[i][j] = 0;
            else if (s == "o")board[i][j] = 1;
            else board[i][j] = 2;
        }
    }
    //枚举落子位置，求解胜负状态并输出
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string result = ".";
            if (board[i][j] == 0) {
                board[i][j] = player;
                if (solve(another_player) == player)result = "!";
                board[i][j] = 0;
            }
            cout << result << " \n"[j == 2];
        }
    }
    return 0;
}