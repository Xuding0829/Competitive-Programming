#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 110;

int n, m;
int a[N][N];
int f[N][N];

signed main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        // f[i, j] 由 f[i - 1][j]  或者  f[i][j  -1] 转移过来

        cout << f[n][m] << endl;
    }
    return 0;
}