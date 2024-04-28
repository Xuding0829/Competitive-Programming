#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 3e5 + 10;
i64 a[N], f[N], g[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    for (int i = 1; i <= 3 * n; i++)
    {
        std::cin >> a[i];
        f[i] = f[i - 1] + a[i];
        q.push(a[i]);
        if (q.size() > n) // 此处实际只有n...2n的部分对答案有贡献
        {
            f[i] -= q.top();
            q.pop();
        }
    } // max

    while (q.size())
        q.pop();

    for (int i = 3 * n; i > 0; i--)
    {
        g[i] = g[i + 1] + a[i];
        q.push(-a[i]);
        if (q.size() > n)
        {
            g[i] += q.top();
            q.pop();
        }
    }

    i64 res = -1e18;
    for (int i = n; i <= 2 * n; i++)
        res = std::max(res, f[i] - g[i + 1]);
    std::cout << res << '\n';
    return 0;
}