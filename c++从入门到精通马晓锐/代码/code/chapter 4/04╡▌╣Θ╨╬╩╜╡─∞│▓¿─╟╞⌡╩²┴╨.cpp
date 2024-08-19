long long F_memory[105];
long long F(int n) {
    if (n == 0 or n == 1)return 1;
    //在记忆化数组中查找计算结果
    else if (F_memory[n] != 0)return F_memory[n];
    else {
        //计算结果并存储到记忆化数组中
        F_memory[n] = F(n - 2) + F(n - 1);
        return F_memory[n];
    }
}