#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    char mins = 'a', mint = 'a';
    char maxs = 'a', maxt = 'a';
    i64 lens = 1, lent = 1;

    while (n--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int k;
            std::string x;
            std::cin >> k >> x;
            for (auto i : x)
            {
                maxs = std::max(maxs, i);
                mins = std::min(mins, i);
                lens += k;
            }
        }
        else
        {
            int k;
            std::string x;
            std::cin >> k >> x;
            for (auto i : x)
            {
                maxt = std::max(maxt, i);
                mint = std::min(mint, i);
                lent += k;
            }
        }

        if (mins < maxt || (mins == mint && maxs == maxt && mins == maxs && lens < lent))
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