#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> mins(22), minv(22);
    std::vector<int> H(22), R(22);
    for (int i = 1; i <= m; i++)
    {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + i * i * 2;
    }

    int res = inf;
    R[m + 1] = H[m + 1] = inf;
    std::function<void(int, int, int)> dfs = [&](int u, int s, int v)
    {
        if (s + mins[u] >= res)
            return;
        if (v + minv[u] > n)
            return;
        if (s + 2 * (n - v) / R[u + 1] >= res)
            return;

        if (!u)
        {
            if (v == n)
                res = s;
            return;
        }

        for (int r = std::min(R[u + 1] - 1, int(std::sqrt((n - v) / u))); r >= u; r--)
        {
            for (int h = std::min(H[u + 1] - 1, (n - v) / r / r); h >= u; h--)
            {
                int t = u == m ? r * r : 0;
                R[u] = r, H[u] = h;
                dfs(u - 1, s + t + 2 * r * h, v + r * r * h);
            }
        }
    };

    dfs(m, 0, 0);
    std::cout << (res == inf ? 0 : res) << '\n';

    return 0;
}