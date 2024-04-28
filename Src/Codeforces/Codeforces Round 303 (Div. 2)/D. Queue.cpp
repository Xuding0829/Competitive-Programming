#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int res = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t <= a[i])
            res++, t += a[i];
    }
    std::cout << res << '\n';

    return 0;
}