#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> odd, even;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        if (x & 1)
            odd.push_back({x, i + 1});
        else
            even.push_back({x, i + 1});
    }

    if (odd.size() == 0 || odd.size() == 2 && even.size() == 1)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";

        int cnt1 = odd.size(), cnt2 = even.size();
        if (cnt1 >= 3)
        {
            for (int i = 0; i < 3; i++)
                std::cout << odd[i].second << ' ';
            std::cout << '\n';
        }
        else
        {
            std::cout << odd[0].second << ' ';
            for (int i = 0; i < 2; i++)
                std::cout << even[i].second << ' ';
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