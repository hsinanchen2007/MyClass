int solve() {
    int ans = n;
    //不按第0个开关
    for (int i = 0; i < n; i++)b[i] = a[i];
    int click = 0;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == 1) {
            click++;
            b[i] = 1 - b[i];
            b[i + 1] = 1 - b[i + 1];
            if (i + 2 < n)b[i + 2] = 1 - b[i + 2];
        }
    }
    if (b[n - 1] == 0)ans = min(ans, click);
    //按第0个开关
    for (int i = 0; i < n; i++)b[i] = a[i];
    b[0] = 1 - b[0];
    if (n > 1)b[1] = 1 - b[1];
    click = 1;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == 1) {
            click++;
            b[i] = 1 - b[i];
            b[i + 1] = 1 - b[i + 1];
            if (i + 2 < n)b[i + 2] = 1 - b[i + 2];
        }
    }
    if (b[n - 1] == 0)ans = min(ans, click);
    return ans;
}