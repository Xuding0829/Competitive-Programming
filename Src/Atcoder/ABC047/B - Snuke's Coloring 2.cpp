#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110;
int g[N][N];
int n, m;
int res;

signed main()
{
    int h, w, n;
    cin >> w >> h >> n;

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            g[i][j] = 1;

    // 模拟题意 - 繁琐
    while (n--)
    {
        int x, y, a;
        cin >> x >> y >> a;

        if (a == 1)
        {
            for (int i = 1; i <= h; i++)
                for (int j = 1; j <= x; j++)
                    g[i][j] = 0;
        }
        else if (a == 2)
        {
            for (int i = 1; i <= h; i++)
                for (int j = x + 1; j <= w; j++)
                    g[i][j] = 0;
        }
        else if (a == 3)
        {
            for (int i = 1; i <= y; i++)
                for (int j = 1; j <= w; j++)
                    g[i][j] = 0;
        }
        else
        {
            for (int i = y + 1; i <= h; i++)
                for (int j = 1; j <= w; j++)
                    g[i][j] = 0;
        }
    }

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            res += g[i][j];

    cout << res << endl;
    return 0;
}
/*
题意：不断缩小白色矩形的面积 求最后白色矩形的面积
用x1, y1, x2, y2 存储矩形的四个顶点坐标
*/
