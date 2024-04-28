#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        std::cin >> v >> w >> s;
        if (s == 0) // 完全背包
        {
            for (int j = v; j <= m; j++)
                f[j] = std::max(f[j], f[j - v] + w);
        }
        else
        {
            if (s == -1)
                s = 1;
            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = m; j >= v * k; j--)
                    f[j] = std::max(f[j], f[j - v * k] + k * w);
                s -= k;
            }
            if (s)
                for (int j = m; j >= v * s; j--)
                    f[j] = std::max(f[j], f[j - s * v] + s * w);
        }
    }
    std::cout << f[m] << '\n';
    return 0;
}

/*
    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        std::cin >> v >> w >> s;
        if (s == 0) // 完全背包
        {
            for (int j = v; j <= m; j++)
                f[j] = std::max(f[j], f[j - v] + w);
        }
        else if (s == -1) // 01背包
        {
            for (int j = m; j >= v; j--)
                f[j] = std::max(f[j], f[j - v] + w);
        }
        else if (s > 0) // 多重背包
        {
            for (int j = m; j >= 0; j--)
                for (int k = 0; k <= s && k * v <= j; k++)
                    f[j] = std::max(f[j], f[j - k * v] + k * w);
        }
    }
    std::cout << f[m] << '\n';
*/