#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<i64, i64>> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].first >> a[i].second;

    std::vector<std::pair<i64, i64>> ch(m + 1);
    for (int i = 1; i <= m; i++)
        std::cin >> ch[i].first >> ch[i].second;

    for (int i = 1; i <= n; i++)
    {
        i64 idx = 1, dis = 1e18;
        for (int j = 1; j <= m; j++)
        {
            i64 tmp = abs(a[i].first - ch[j].first) + abs(a[i].second - ch[j].second);
            if (tmp < dis)
                dis = tmp, idx = j;
        }
        std::cout << idx << '\n';
    }
    return 0;
}