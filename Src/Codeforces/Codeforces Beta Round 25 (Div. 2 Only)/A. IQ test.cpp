#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> odd, even;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x & 1)
            odd.push_back({x, i});
        else
            even.push_back({x, i});
    }

    if (odd.size() == 1)
        std::cout << odd[0].second + 1;
    else
        std::cout << even[0].second + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    // std::cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}