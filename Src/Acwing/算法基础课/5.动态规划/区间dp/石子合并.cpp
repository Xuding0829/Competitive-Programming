#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> s[i], s[i] += s[i - 1];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; k++)
                f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    }
    
    std::cout << f[1][n] << '\n';
    return 0;
}