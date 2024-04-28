#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> num(10);
    std::iota(num.begin(), num.end(), 0);
    for (int i = 0, x; i < n; i++)
    {
        std::string s;
        std::cin >> x >> s;

        int sum = 0;
        for (auto it : s)
        {
            if (it == 'D')
                sum++;
            else
                sum--;
        }

        int cur = a[i];
        cur = (a[i] + sum + 10) % 10;
        std::cout << cur << " \n"[i == n - 1];
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