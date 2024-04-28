#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> even, odd;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x & 1)
            odd.emplace_back(x);
        else
            even.emplace_back(x);
    }

    for (auto i : odd)
        std::cout << i << ' ';
    for (auto i : even)
        std::cout << i << ' ';
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}