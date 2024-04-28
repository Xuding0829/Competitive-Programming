#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;

    s = ' ' + s;
    int m = s.size() - 1;
    std::vector<int> next(60);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && s[i] != s[j + 1])
            j = next[j];
        if (s[i] == s[j + 1])
            j++;
        next[i] = j;
    }

    std::vector<std::vector<int>> f(60, std::vector<int>(60));
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            for (char k = 'a'; k <= 'z'; k++)
            {
                int u = j;
                while (u && k != s[u + 1])
                    u = next[u];
                if (k == s[u + 1])
                    u++;
                if (u < m)
                    f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }
        }

    int res = 0;
    for (int i = 0; i < m; i++)
        res = (res + f[n][i]) % mod;
    std::cout << res << '\n';
    return 0;
}