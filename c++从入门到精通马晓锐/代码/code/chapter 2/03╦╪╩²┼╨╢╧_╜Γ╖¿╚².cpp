bool isPrime(int n) {
    //n=1 的情况需要单独处理
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; //如果n能被i整除，那么n不是素数
    }
    return true;
}