#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    // std::vector<int> a(n + 1);
    // for (int i = 0; i < n; i++)
    //     a[i] = k / n;
    // a[n - 1] += k % n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         std::cout << a[j] << ' ';
    //     std::cout << '\n';

    //     for (int j = n; j > 0; j--)
    //         a[j] = a[j - 1];
    //     a[0] = a[n];
    // }

    // 最简单
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}