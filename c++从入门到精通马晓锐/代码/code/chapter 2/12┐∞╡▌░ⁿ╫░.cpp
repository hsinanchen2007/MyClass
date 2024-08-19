#include<bits/stdc++.h>
using namespace std;

//每件快递用一个结构体来表示高度和长度
struct Package {
    int L, W;
};
//排序规则
bool compare_package(const Package &a, const Package &b) {
    if (a.L != b.L)return a.L > b.L;
    else return a.W > b.W;
}
//快递数量
int n;
//每件快递
Package package[1005];
//每个队列的队尾的快递
Package tail[1005];

int main() {
    //输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> package[i].L;
    }
    for (int i = 0; i < n; i++) {
        cin >> package[i].W;
    }
    //排序
    sort(package, package + n, compare_package);
    //队列数量
    int queue_num = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < queue_num; j++) {
            //找到最早出现的能容纳这件快递的队列
            if (tail[j].L >= package[i].L and tail[j].W >= package[i].W) {
                tail[j] = package[i];
                flag = false;
                break;
            }
        }
        //如果没有能容纳这件快递的队列，则新建队列
        if (flag) {
            tail[queue_num] = package[i];
            queue_num++;
        }
    }
    //输出，答案=队列个数+快递个数
    cout << queue_num + n << endl;
    return 0;
}