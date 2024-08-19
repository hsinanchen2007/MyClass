#include <bits/stdc++.h>
using namespace std;

//灯的个数与每盏灯的状态
int n, a[100005];
//b数组用来存储某一方案对应的结果
int b[100005];

int solve() {
    //总方案数=2的n次方
    int max_s = 1 << n;
    //最少需要按开关的次数
    int ans = n;
    //遍历0到2^n-1范围内每一个数
    for (int s = 0; s < max_s; s++) {
        //先把a数组复制到b数组中，在b数组中进行计算，避免覆盖原数据
        for (int i = 0; i < n; i++)b[i] = a[i];
        //click变量用来记录当前方案按的次数
        int click = 0;
        //进行二进制分解
        int temp = s;
        for (int i = 0; i < n; i++) {
            if (temp % 2 == 1) {
                //按下第i个开关，相关的三盏灯状态发生改变
                click++;
                b[i] = 1 - b[i];
                if (i > 0)b[i - 1] = 1 - b[i - 1];
                if (i < n - 1)b[i + 1] = 1 - b[i + 1];
            }
            temp /= 2;
        }
        //检验是否所有的灯已关闭
        bool close = true;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1)close = false;
        }
        //更新答案
        if (close)ans = min(ans, click);
    }
    return ans;
}


int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //求解并输出
    cout << solve() << endl;
    return 0;
}