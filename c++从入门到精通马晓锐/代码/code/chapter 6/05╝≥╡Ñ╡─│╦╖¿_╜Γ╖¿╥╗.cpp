#include <bits/stdc++.h>
using namespace std;

// 进制数
const int Base=10;
//把字符串转化为vector<int>
vector<int> string2vector(const string &s) {
    int n = s.size();
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)v[i] = s[n - i - 1] - '0';
    return v;
}
//输出大数c
void output(vector<int> c) {
    if (c.size() == 0) {
        cout << "0" << endl;
    } else {
        reverse(c.begin(), c.end());
        for (int i = 0; i < (int)c.size(); i++)cout << c[i];
        cout << endl;
    }
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

int main() {
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a = string2vector(sa), b = string2vector(sb);
    vector<int> c = b_mul(a, b);
    output(c);
    return 0;
}