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
    if (n == 1)
        std::cout << "YES\n";
    else
    {
        bool flag = false;
        for (int i = 1; i < n; i++)
            if (a[i] <= a[i - 1])
                flag = true;

        std::cout << (flag ? "NO\n" : "YES\n");
    }
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