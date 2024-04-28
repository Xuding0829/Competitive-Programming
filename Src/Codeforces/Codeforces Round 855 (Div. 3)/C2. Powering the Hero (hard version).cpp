#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    i64 res = 0;
    std::vector<i64> a(n);
    std::priority_queue<i64, std::vector<i64>, std::less<>> q;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i])
            q.push(a[i]);
        else if (!a[i] && !q.empty())
            res += q.top(), q.pop();
    }

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