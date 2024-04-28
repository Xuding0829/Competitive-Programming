#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string a, b;
    std::cin >> a >> b;
    std::cout << (a.substr(n - m + 1) == b.substr(1) && std::count(a.begin(), a.begin() + n - m + 1, b[0]) ? "YES\n" : "NO\n");
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