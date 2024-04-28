#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, h;
    std::cin >> n >> h;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int res = 0;
    std::string s[3];
    s[0] = "223", s[1] = "232", s[2] = "322";

    auto get = [&](int order)
    {
        int cnt = 0;
        i64 t = h;
        int now = 0;
        for (int i = 0; i < n;)
        {
            if (a[i] < t)
                t += a[i] / 2, cnt++, i++;
            else
            {
                if (now + 1 <= 3)
                    t *= (i64)s[order][now++] - '0';
                else
                    break;
            }
        }
        return cnt;
    };

    for (int i = 0; i < 3; i++)
        res = std::max(res, get(i));
    std::cout << res << '\n';
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