#include <bits/stdc++.h>

using i64 = long long;

int f[4100];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b, c;
    std::cin >> n >> a >> b >> c;

    f[a] = f[b] = f[c] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i > a && f[i - a])
            f[i] = std::max(f[i], f[i - a] + 1);
        if (i > b && f[i - b])
            f[i] = std::max(f[i], f[i - b] + 1);
        if (i > c && f[i - c])
            f[i] = std::max(f[i], f[i - c] + 1);
    }
    std::cout << f[n] << '\n';

    return 0;
}