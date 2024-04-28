#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int s[N];

signed main()
{
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        s[i] += s[i - 1] + x;
    }
    // 前缀和维护
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}