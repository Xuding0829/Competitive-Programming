#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], v[i] = {a[i], i};
    std::sort(v.begin(), v.end());

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    std::sort(b.begin(), b.end());

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[v[i].second] = b[i];
    for (auto x : c)
        std::cout << x << ' ';
    std::cout << '\n';
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