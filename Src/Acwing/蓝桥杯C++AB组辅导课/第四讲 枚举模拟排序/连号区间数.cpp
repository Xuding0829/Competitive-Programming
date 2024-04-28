#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 注意审题
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxn = -0x3f3f3f, minn = 0x3f3f3f;
        for (int j = i; j <= n; j++)
        {
            maxn = max(maxn, a[j]);
            minn = min(minn, a[j]);
            if (maxn - minn == j - i) // 满足连续 最大值 - 最小值 = 下标之差
                res++;
        }
    }

    cout << res << endl;
    return 0;
}