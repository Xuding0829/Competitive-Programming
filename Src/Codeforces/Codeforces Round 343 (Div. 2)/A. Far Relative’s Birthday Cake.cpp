#include <bits/stdc++.h>

using i64 = long long;

i64 C(int a, int b)
{
    return a * (a - 1) / 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> row(n), col(n);
    std::vector<std::vector<char>> g(n, std::vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            std::cin >> g[i][j];
            if (g[i][j] == 'C')
                row[i]++, col[j]++;
        }

    i64 res = 0;
    for (int i = 0; i < n; i++)
        res += C(row[i], 2) + C(col[i], 2);
    std::cout << res << '\n';

    return 0;
}