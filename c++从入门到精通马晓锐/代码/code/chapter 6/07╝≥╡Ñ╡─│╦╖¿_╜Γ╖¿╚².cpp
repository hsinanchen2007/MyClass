#include <bits/stdc++.h>
using namespace std;

//进制数
const int Base = 1000;
const int W = 3;
//把字符串转化为vector<int>
vector<int> string2vector(string s) {
    reverse(s.begin(), s.end());
    vector<int> c;
    for (int i = 0; i * W < (int)s.size(); i++) {
        int num = 0;
        //相邻的W位构成一位
        for (int j = i * W + W - 1; j >= i * W; j--) {
            if (j < (int)s.size())num = num * 10 + s[j] - '0';
        }
        c.emplace_back(num);
    }
    return c;
}
//输出大数c
void output(vector<int> c) {
    if (c.size() == 0) {
        cout << "0" << endl;
    } else {
        reverse(c.begin(), c.end());
        for (int i = 0; i < (int)c.size(); i++) {
            //注意某些数字输出时需要在前边补0哦
            if (i == 0)cout << c[i];
            else cout << setfill('0') << std::setw(W) << c[i];
        }
        cout << endl;
    }
}
//加法
vector<int> add(const vector<int> &a, const vector<int> &b) {
    int n = max(a.size(), b.size());
    vector<int> c;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (i < (int)a.size())num += a[i];
        if (i < (int)b.size())num += b[i];
        c.emplace_back(num % Base);
        num /= Base;
    }
    if (num > 0)c.emplace_back(num);
    return c;
}
//减法
vector<int> sub(const vector<int> &a, const vector<int> &b) {
    vector<int> c = a;
    for (int i = 0; i < (int)b.size(); i++) {
        c[i] -= b[i];
        if (c[i] < 0) {
            c[i] += Base;
            c[i + 1] -= 1;
        }
    }
    while (c.size() > 0 and c.back() == 0)c.pop_back();
    return c;
}
//模拟竖式计算c=a*b
vector<int> b_mul(const vector<int> &a, const vector<int> &b) {
    int n = a.size() + b.size() - 1;
    vector<int> c(n, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        //将a的第i位分别与b的每一位相乘
        for (int j = 0; j < (int)b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
        //处理进位
        int num = 0;
        for (int i = 0; i < n; i++) {
            num += c[i];
            c[i] = num % Base;
            num /= Base;
        }
        while (num > 0) {
            c.emplace_back(num % Base);
            num /= Base;
        }
    }
    return c;
}
//分治计算c=a*b
vector<int> k_mul(const vector<int> &a, const vector<int> &b) {
    //当数较小时，调用模拟竖式乘法
    if (a.size() < 100 or b.size() < 100)return b_mul(a, b);
    //选取较大数字的中间位置作为拆分位置（以下所有代码未发生改变）
    int length = max(a.size(), b.size()) / 2;
    //拆分为A、B、C、D
    int length_a = min(length, (int)a.size());
    vector<int> A(a.begin() + length_a, a.end());
    vector<int> B(a.begin(), a.begin() + length_a);
    int length_b = min(length, (int)b.size());
    vector<int> C(b.begin() + length_b, b.end());
    vector<int> D(b.begin(), b.begin() + length_b);
    //计算AC、BD
    vector<int> AC = k_mul(A, C);
    vector<int> BD = k_mul(B, D);
    //计算E=(A+B)(C+D)-AC-BD=AD+BC
    vector<int> E = sub(sub(k_mul(add(A, B), add(C, D)), AC), BD);
    //计算ACx^2、(AD+BC)x，即插入0
    vector<int> x(length, 0);
    E.insert(E.begin(), x.begin(), x.end());
    AC.insert(AC.begin(), x.begin(), x.end());
    AC.insert(AC.begin(), x.begin(), x.end());
    //计算ACx^2+(AD+BC)x+BD
    return add(add(AC, E), BD);
}

int main() {
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a = string2vector(sa), b = string2vector(sb);
    vector<int> c = k_mul(a, b);
    output(c);
    return 0;
}