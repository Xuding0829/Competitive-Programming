#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 5010;

int n, m, q;
int s[N][N];

signed main()
{
    cin >> n >> m >> q;
    // 对于子矩阵问题可以画出表格
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + x;
            // 通过割补法求得i,j 的前缀和 s[i,j] = s[i,j-1] + s[i - 1][j] -s[i - 1][j - 1] + a[i][j]
            // 即s[i,j]等于左侧i，j-1矩阵 加上 上方 i-1，j矩阵 由于i-1，j-1加了两遍要减去最后再加上a[i,j]
        }

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
        // 子矩阵之和等于x2,y2矩阵减去x2,y1-1 和 x1-1,y2 矩阵加上x1-1 y1-1矩阵
    }
    return 0;
}
