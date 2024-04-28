#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::vector<int>> f(1010, std::vector<int>(1010));
// 放函数中会tle

int edit_distance(std::string a, std::string b)
{
    int n = a.size(), m = b.size();

    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 0; i <= m; i++)
        f[0][i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = 1 + std::min(f[i - 1][j], std::min(f[i - 1][j - 1], f[i][j - 1]));
        }
    return f[n][m];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], a[i] = ' ' + a[i];

    while (m--)
    {
        int op;
        std::string s;
        std::cin >> s >> op;
        s = ' ' + s;

        int res = 0;
        for (int i = 0; i < n; i++)
            if (edit_distance(a[i], s) <= op)
                res++;
        std::cout << res << '\n';
    }

    return 0;
}