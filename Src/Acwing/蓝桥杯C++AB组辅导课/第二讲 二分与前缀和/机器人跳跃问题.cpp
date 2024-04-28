#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int h[N];

bool check(int e)
{
    for (int i = 1; i <= n; i++)
    {
        e = 2 * e - h[i]; // 由题意可以推出跳跃后的能量
        if (e < 0)
            // 存在负数个单位
            return false;
        if (e > 1e5)
            // 如果存在某次跳跃，使得e大于1e5，那么无论输入都可以到达终点
            return true;
    }
    return true;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int l = 1, r = 1e5;
    // 二分答案
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) // 如果mid可以到达，缩小r
            r = mid;
        else // 如果mid到达不了，扩大l
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}