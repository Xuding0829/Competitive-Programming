#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;
typedef pair<int, int> PII;

const int N = 100;

int n, m;
char g[N][N], backup[N][N];

// 映射函数
long get(int x, int y)
{
    return 4 * x + y;
}

// 翻转
void turn_one(int x, int y)
{
    if (g[x][y] == '+')
        g[x][y] = '-';
    else
        g[x][y] = '+';
}
void turn_all(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        turn_one(i, y);
        turn_one(x, i);
    }
    turn_one(x, y);
}

signed main()
{
    for (int i = 0; i < 4; i++)
        cin >> g[i];

    // res用于存储答案
    vector<PII> res;

    // 一共16位，枚举每一位上的情况，如果是1，就按不是1就不按
    for (int op = 0; op < 1 << 16; op++)
    {
        vector<PII> temp;
        // backup用于备份
        memcpy(backup, g, sizeof(g));

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (op >> get(i, j) & 1)
                {
                    turn_all(i, j);
                    temp.push_back({i, j});
                }
        // 判断是否全部闭合
        bool is_close = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (g[i][j] == '+')
                    is_close = false;

        if (is_close)
            if (res.empty() || temp.size() < res.size())
                res = temp;
        // 第一次操作或者操作次数更少就更新答案

        memcpy(g, backup, sizeof(backup));
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        // 由于开始i，j以0，0存储，题目要求从1，1开始，first second需要加1
        cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;

    return 0;
}