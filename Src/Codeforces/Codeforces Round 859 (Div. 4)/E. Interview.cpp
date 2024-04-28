#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], s[i] = s[i - 1] + a[i];

    int l = 1, r = n, ans = -1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        std::cout << "? " << mid - l + 1 << ' ';
        for (int i = l; i <= mid; i++)
            std::cout << i << ' ';
        std::cout << "\n";
        std::cout.flush();

        std::cin >> ans;
        if (ans != s[mid] - s[l - 1])
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << "! " << l << '\n';
    std::cout.flush();
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