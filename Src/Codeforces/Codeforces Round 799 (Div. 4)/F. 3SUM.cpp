#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a;
    int cnt[10] = {0};
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        x %= 10;
        if (cnt[x] < 3)
        {
            cnt[x]++;
            a.push_back(x);
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                if ((a[i] + a[j] + a[k]) % 10 == 3)
                {
                    std::cout << "YES\n";
                    return;
                }
            }
        }
    }
    std::cout << "NO\n";
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