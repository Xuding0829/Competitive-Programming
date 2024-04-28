#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    int sum = 0;
    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i], sum += a[i];
        s[i] = s[i - 1] + a[i];
    }

    while (q--)
    {
        int l, r, k, tmp = sum;
        std::cin >> l >> r >> k;
        tmp -= s[r] - s[l - 1] + k * (r - l + 1);
        if (tmp & 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
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