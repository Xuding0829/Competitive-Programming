#include <bits/stdc++.h>

using i64 = long long;

const int inf = 0x3f3f3f3f;

int g[1010][1010][2], f[1010][1010][2];
// std::stack<char> stk;

int get_cnt(int x, int k)
{
    int res = 0;
    while (x % k == 0)
    {
        x /= k;
        res++;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    // scanf("%d", &n);

    int pos = 0, u, v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1, x; j <= n; j++)
        {
            std::cin >> x;
            // scanf("%d", &x);
            if (!x)
            {
                pos = i;
                g[i][j][0] = g[i][j][1] = 1;
                u = i, v = j;
                continue;
            }
            else
            {
                g[i][j][0] = get_cnt(x, 2);
                g[i][j][1] = get_cnt(x, 5);
            }
        }
    }

    for (int i = 0; i <= n; i++)
        f[0][i][0] = f[i][0][0] = f[0][i][1] = f[i][0][1] = inf;
    f[1][1][0] = g[1][1][0], f[1][1][1] = g[1][1][1];
    for (int k = 0; k < 2; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; ++j)
                if (i == 1 && j == 1)
                    continue;
                else
                    f[i][j][k] = std::min(f[i][j - 1][k], f[i - 1][j][k]) + g[i][j][k];

    int res = !(f[n][n][0] < f[n][n][1]);
    if (pos && f[n][n][res] > 1)
    {
        std::cout << 1 << '\n';
        for (int i = 1; i < u; i++)
            std::cout << 'D';
        for (int i = 1; i < v; i++)
            std::cout << 'R';
        for (int i = u; i < n; i++)
            std::cout << 'D';
        for (int i = v; i < n; i++)
            std::cout << 'R';
        return 0;
    }

    int ans = std::min(f[n][n][0], f[n][n][1]);
    std::cout << ans << '\n';

    int i = n, j = n;
    std::string ans2;
    while (1)
    {
        if (f[i][j - 1][res] > f[i - 1][j][res])
            i--, ans2 += 'D';
        else
            j--, ans2 += 'R';

        if (i == 1)
        {
            for (int k = 1; k < j; k++)
                ans2 += 'R';
            break;
        }
        if (j == 1)
        {
            for (int k = 1; k < i; k++)
                ans2 += 'D';
            break;
        }
    }
    std::reverse(ans2.begin(), ans2.end());
    std::cout << ans2 << '\n';
    return 0;
}

/*
递归写法
std::function<void(int, int, int)> print = [&](int i, int j, int k)
{
    if (i == 1 && j == 1)
    {
        std::cout << (k ? 'D' : 'R');
        return;
    }

    if (i == 1)
        print(i, j - 1, 0);
    else if (j == 1)
        print(i - 1, j, 1);
    else if (f[i][j][res] == f[i - 1][j][res] + g[i][j][res])
        print(i - 1, j, 1);
    else
        print(i, j - 1, 0);

    if (i != n || j != n)
        std::cout << (k ? 'D' : 'R');
};
*/
