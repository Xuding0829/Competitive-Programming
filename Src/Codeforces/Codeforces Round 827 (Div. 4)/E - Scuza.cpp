#include <bits/stdc++.h>

using i64 = long long;

void solve()
{

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    std::vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
        a[i] = std::max(a[i - 1], a[i]);
    }

    while (m--)
    {
        i64 k;
        std::cin >> k;

        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= k)
                l = mid;
            else
                r = mid - 1;
        }
        std::cout << s[l] << " \n"[m == 0];
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