#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n * 2 + 1);

    for (int i = 1, j = 1; i <= n; i += 2, j++)
        a[j] = i, a[n - j + 1] = i;

    for (int i = 2, j = 1; i <= n; i += 2, j++)
        a[j + n] = i, a[2 * n - j] = i;

    for (int i = 1; i <= 2 * n; i++)
        if (!a[i])
            a[i] = n;

    for (int i = 1; i <= 2 * n; i++)
        std::cout << a[i] << ' ';

    return 0;
}