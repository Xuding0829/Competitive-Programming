#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int odd = 0, even = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int k = a[0];
    if (k % 2)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 == 0 && (a[i] - k) % 2 == 0)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 && (a[i] - k) % 2)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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