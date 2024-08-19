#include <bits/stdc++.h>
using namespace std;

//B和M
const long long B1 = 233, M1 = 1000000007;
const long long B2 = 2333, M2 = 998244353;
//两个字符串
string s1, s2;
//用来存储哈希值的容器
set<pair<long long,long long>> hash_values_1, hash_values_2;

//计算字符串所有长度为half_n的子串的哈希值
void hash_to_set(string &s, int half_n, set<pair<long long,long long>> &hash_values) {
    long long hash_value_1 = 0, hash_value_2 = 0;
    long long pow_B1 = 1, pow_B2 = 1;
    for (int i = 0; i < half_n - 1; i++) {
        pow_B1 = (pow_B1 * B1) % M1;
        pow_B2 = (pow_B2 * B2) % M2;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        //减掉左侧的字符
        if (i >= half_n) {
            hash_value_1 = (hash_value_1 - (long long)s[i - half_n] * pow_B1) % M1;
            if (hash_value_1 < 0)hash_value_1 += M1;
            hash_value_2 = (hash_value_2 - (long long)s[i - half_n] * pow_B2) % M2;
            if (hash_value_2 < 0)hash_value_2 += M2;
        }
        //增加右侧的字符
        hash_value_1 = (hash_value_1 * B1 + (long long)s[i]) % M1;
        hash_value_2 = (hash_value_2 * B2 + (long long)s[i]) % M2;
        //把哈希值存入hash_values
        if (i >= half_n - 1) {
            hash_values.insert(make_pair(hash_value_1, hash_value_2));
        }
    }
}
//检验两个哈希值集合是否有公共元素
bool check() {
    for (auto i : hash_values_1) {
        if (hash_values_2.count(i))return true;
    }
    return false;
}

int main() {
    //输入
    getline(cin, s1);
    getline(cin, s2);
    //计算两字符串所有长度为n/2的子串的哈希值
    int half_n = s1.size() / 2;
    hash_to_set(s1, half_n, hash_values_1);
    hash_to_set(s2, half_n, hash_values_2);
    //检验两个哈希值集合是否有公共元素
    if (check()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}