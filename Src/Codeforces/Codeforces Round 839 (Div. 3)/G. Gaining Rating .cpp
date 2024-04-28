#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 n, x, y;
    std::cin >> n >> x >> y;

    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    i64 change = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
            b[i] = 1, x++, change++, ans++;
        else
            b[i] = -1, x--, change--, ans++;
        if (x >= y)
        {
            std::cout << ans << '\n';
            return;
        }
    }

    if (change <= 0)
    {
        std::cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {

        if (b[i] == -1)
        {
            i64 k = ceil((a[i] - i - x) * 1.0 / change);
            i64 t = ceil((y - i - x) * 1.0 / change);

            if (t <= k)
            {
                ans += t * n;
                x += t * change;

                for (int j = 0; j < n; j++)
                {
                    ans++;
                    if (a[j] <= x)
                        x++;
                    else
                        x--;
                    if (x >= y)
                    {
                        std::cout << ans << '\n';
                        return;
                    }
                }
            }

            ans += k * n;
            x += k * change;
            change += 2;
        }
    }
    std::cout << ans + y - x << '\n';
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