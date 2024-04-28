#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int h[N], w[N];

bool check(int mid)
{
    // res代表可成巧克力的数量
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (h[i] / mid) * (w[i] / mid);
        if (res >= m)
            // 如果巧克力数量大于人数，说明这个方案是可行的，否则是不可行的
            return true;
    }
    if (res >= m)
        return true;
    else
        return false;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    // 二分答案
    int l = 1, r = 1e5;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            // 方案可行，要实现巧克力的边长尽可能地大， 要扩大l
            l = mid;
        else
            // 方案不可行，巧克力的边长要缩小
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}