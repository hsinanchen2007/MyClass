int solve(int i, int sum, int num) {
    if (i == n) {
        if (sum == s)return num;
        else return inf;
} else {
        //在这里添加剪枝判断条件
        if (sum > s)return inf;
        else {
            return min(
                solve(i + 1, sum + a[i], num + 1),
                solve(i + 1, sum, num)
            );
        }
    }
}