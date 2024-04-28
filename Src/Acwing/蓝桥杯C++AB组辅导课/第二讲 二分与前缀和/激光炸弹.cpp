#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

using namespace std;

const int N = 5100;

int n, m, r;
int s[N][N];

signed main()
{
    cin >> n >> r;
    r = min(r, 5001);

    while (n--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
    }

    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++)
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];

    int res = 0;
    for (int i = r; i <= 5001; i++)
        for (int j = r; j <= 5001; j++)
            res = max(res, s[i][j] - s[i][j - r] - s[i - r][j] + s[i - r][j - r]);

    cout << res << endl;

    return 0;
}