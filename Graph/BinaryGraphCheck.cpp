#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int N; //表示图的大小
vector<int> G[MAXN]; // 初始输入
short colors[MAXN]; // 每个节点所涂的颜色


bool dfs(int node, short color) {
    colors[node] = color; // 首先将节点进行涂色
    for (int i = 0; i < G[node].size(); i++) {
        if (colors[G[node][i]] == colors[node]) return false; // 颜色相同就返回false
        if (colors[G[node][i]] == 0 && !dfs(G[node][i], -color)) return false; // 未涂色, 但是后来发生退化, 返回false
    }
    return true; // 将所有的顺利涂色情况都归结到这里, 比如颜色匹配等等, 这种写法就很方便进行dfs
}

void solve() {
    bool result;
    for (int i = 0; i < N; i++) {
        if (!colors[i]) { // 如果当前节点没有涂色
            result = dfs(i, 1); // 进行dfs遍历
            if (!result) { // 如果无法涂色, 返回false
                cout << "No" << endl;
                break;
            }
        }
    }
}