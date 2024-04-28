#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
    }

    if (cnt)
    {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            a.push_back(i);
        else
            b.push_back(i);
    }

    std::vector<int> res(n, 2);
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] < b[i])
            res[a[i]] = res[b[i]] = 1;
        else
            res[a[i]] = res[b[i]] = 2;
    }

    if (*std::min_element(res.begin(), res.end()) == 2)
        std::fill(res.begin(), res.end(), 1);

    std::cout << *std::max_element(res.begin(), res.end()) << '\n';
    for (int i = 0; i < n; i++)
        std::cout << res[i] << " \n"[i == n - 1];
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