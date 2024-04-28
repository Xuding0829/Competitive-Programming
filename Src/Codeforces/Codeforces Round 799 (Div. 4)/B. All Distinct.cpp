#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> mp;
    for (int i = 0, x; i < n; i++)
        std::cin >> x, mp[x]++;

    if (mp.size() == n)
    {
        std::cout << n << '\n';
        return;
    }

    for (auto [u, v] : mp)
    {
        if (v > 1)
            v = 1;
    }

    int del = n - mp.size();
    if (del & 1)
        std::cout << mp.size() - 1 << '\n';
    else
        std::cout << mp.size() << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}