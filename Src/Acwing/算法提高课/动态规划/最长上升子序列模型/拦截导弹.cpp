#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::vector<int> a(1010);
    while (std::cin >> a[n])
        n++;

    int res = 0;
    std::vector<int> f(n), g(n);
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] <= a[j])
                f[i] = std::max(f[i], f[j] + 1);
        res = std::max(res, f[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        while (k < cnt && g[k] < a[i])
            k++;
        g[k] = a[i];
        if (k >= cnt)
            cnt++;
    }

    std::cout << res << '\n';
    std::cout << cnt << '\n';

    return 0;
}