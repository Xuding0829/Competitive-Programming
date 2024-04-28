#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int odd = 0;
    std::vector<int> even;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x % 2)
            odd++;
        else
            even.push_back(x);
    }

    if (odd == n)
        std::cout << "0\n";
    else if (odd)
        std::cout << even.size() << '\n';
    else
    {
        std::vector<int> times;
        for (auto i : even)
        {
            int cnt = 0;
            while (i % 2 == 0)
            {
                cnt++;
                i /= 2;
            }
            times.emplace_back(cnt);
        }

        std::sort(times.begin(), times.end());

        int res = times[0] + even.size() - 1;
        std::cout << res << '\n';
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