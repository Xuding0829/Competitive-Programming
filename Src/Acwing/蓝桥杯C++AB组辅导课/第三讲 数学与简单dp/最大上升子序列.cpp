#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2100;

int n, m;
int a[N];
int f[N]; // f[i] 表示以 a[i] 结尾 的 最大上升子序列

signed main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (a[i] > a[j])
                // f[i] 由 第 k 个 元素 转移
                f[i] = max(f[i], f[j] + 1);
        }
    }

    int res = 0;
    // 寻找最大值
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;

    return 0;
}