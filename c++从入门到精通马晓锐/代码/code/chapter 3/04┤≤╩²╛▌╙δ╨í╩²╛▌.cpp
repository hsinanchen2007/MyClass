#include <bits/stdc++.h>
using namespace std;

//题目中的变量
int n, p[1000005];
//穷举算法
void bruteforce() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if ((p[i] + p[j] + p[k] + p[l]) % 4 == 0) {
                        cout << p[i] << " " << p[j] << " " << p[k] << " " << p[l] << endl;
                        return;
                    }
                }
            }
        }
    }
}
//采样前13个
void sample13() {
    vector<int> num[4];
    for (int i = 0; i < 13; i++) {
        int category = p[i] % 4;
        num[category].push_back(p[i]);
        //当某一类数达到4个时，把这四个数输出
        if (num[category].size() == 4) {
            for (int j = 0; j < 4; j++) {
                cout << num[category][j] << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if (n < 13) {
        bruteforce();//对于小数据，用穷举算法暴力解决
    } else {
        sample13();  //对于大数据，采样前13个
    }
    return 0;
}