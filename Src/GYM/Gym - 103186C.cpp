#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int sum = 0;
    std::map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int s, a;
        std::cin >> s >> a;
        sum += a;

        if (s == m)
            a = std::max(a, 60);

        mp[s] = a;
    }

    double ave = (double)sum / n;

    for (auto &[u, v] : mp)
    {
        if (u != m && v >= ave)
        {
            v = std::max(0, v - 2);
        }
    }

    for (auto [u, v] : mp)
        std::cout << v << ' ';

    return 0;
}