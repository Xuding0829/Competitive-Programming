#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int st = 0, ed = 0;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] != i && !st)
            st = i;
    }

    ed = st;
    while (a[ed] != st)
        ed++;
    std::reverse(a.begin() + st, a.begin() + ed + 1);

    for (int i = 1; i <= n; i++)
        std::cout << a[i] << ' ';
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