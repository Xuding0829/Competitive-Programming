#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    if (n == 2)
    {
        std::cout << a[0] << ' ' << a[1] << '\n';
        return;
    }

    int x = 1;
    for (int i = 2; i < n; i++)
        if (a[i] - a[i - 1] < a[x] - a[x - 1])
            x = i;

    for (int i = x; i < n; i++)
        std::cout << a[i] << ' ';
    for (int i = 0; i < x; i++)
        std::cout << a[i] << " \n"[i == x - 1];
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