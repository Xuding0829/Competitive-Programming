#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n < 4)
        std::cout << "-1\n";
    else
    {
        if (n == 4)
            std::cout << "2 4 1 3\n";
        else
        {
            std::vector<int> a(n);
            int cnt = 0;
            for (int i = n; i >= 1; i--)
                if (i & 1)
                    a[cnt++] = i;
            a[cnt++] = 4, a[cnt++] = 2;
            for (int i = 5; i <= n; i++)
                if (i % 2 == 0)
                    a[cnt++] = i;

            for (int i = 0; i < n; i++)
                std::cout << a[i] << ' ';
            std::cout << '\n';
        }
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