#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N], b[N];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        // 构造差分数组b
    }

    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
        // 对于一段区间，同时加上或者减去一个数c，相当于对其差分数组的l  +1 ，r+１ -c
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    // 计算前缀和，求出原数组
    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    // 输出
    return 0;
}