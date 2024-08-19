bool isPrime(int n) {
    //n较小的情况需要单独处理
    if (n == 2 or n == 3 or n == 5)return true;
    if (n == 1 or n % 2 == 0 or n % 3 == 0 or n % 5 == 0)return false;
    //遍历2到sqrt(n)中的 6k+1 与 6k+5
    int i = 7;
    while (i * i <= n) {
        if (n % i == 0)return false;
        i += 4;
        if (n % i == 0)return false;
        i += 2;
    }
    return true;
}