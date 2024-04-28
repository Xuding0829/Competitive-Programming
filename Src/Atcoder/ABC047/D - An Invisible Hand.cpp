#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int f[N];
int n, m;
int res;

// 思路： 从后往前遍历，找到最大利润，A在最大利润的时候出售，此时B改价格，因此题目转换找差值为最大利润的数量

signed main()
{
    int n, t;
    int maxn = INT_MIN, tmp = INT_MIN;

    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--)
    {
        tmp = max(tmp, a[i]);         // 最大价格
        maxn = max(maxn, tmp - a[i]); // 最大利润
    }

    // cout << "maxn " << maxn << endl;

    tmp = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        tmp = max(tmp, a[i]);
        if (tmp - a[i] == maxn)
            res++;
    }
    cout << res << endl;
    return 0;
}