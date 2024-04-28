#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
        if (b[i] < a[i])
            std::swap(a[i], b[i]);
    }

    i64 mx = *std::max_element(b.begin(), b.end());
    i64 mn = *std::max_element(a.begin(), a.end());
    i64 res = mx * mn;
    std::cout << res << '\n';
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