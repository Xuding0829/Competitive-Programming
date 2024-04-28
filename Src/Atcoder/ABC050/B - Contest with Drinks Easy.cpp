#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, sum = 0;
    std::cin >> n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++)
        std::cin >> t[i], sum += t[i];

    int m;
    std::cin >> m;
    std::vector<std::pair<int, int>> v(m);

    for (int i = 0; i < m; i++)
    {
        int p, x;
        std::cin >> p >> x;
        v[i] = {p, x};
    }

    for (int i = 0; i < m; i++)
    {
        auto x = v[i].first, y = v[i].second;
        int tmp = sum;
        tmp = sum - t[x - 1] + y;
        std::cout << tmp << "\n";
    }

    return 0;
}