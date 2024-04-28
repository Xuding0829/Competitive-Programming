#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 1100;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y2 + 1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    // b[x1,y1] + c 后 右下角都加了c
    // b[x1, y2 + 1] b[x2 + 1, y1]都要减去一个c
    // b[x2 + 1][y2 + 1] 减了两次c，要加上一个c
}

signed main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
            // 构造差分据矩阵b
        }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
    // 差分矩阵的前缀和即是原矩阵

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << ' ';
        puts("");
        // 输出
    }
    return 0;
}