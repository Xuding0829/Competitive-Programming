#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

signed main()
{
    cin >> n;
    while (cin >> a[m++])
        ;
    int res1, res2;
    sort(a, a + m);
    for (int i = 1; i < m; i++)
    {
        if (a[i] == a[i - 1])
            res1 = a[i]; // 重号
        else if (a[i] - a[i - 1] >= 2)
            res2 = a[i - 1] + 1; // 断号
    }
    cout << res2 << ' ' << res1 << endl;

    return 0;
}