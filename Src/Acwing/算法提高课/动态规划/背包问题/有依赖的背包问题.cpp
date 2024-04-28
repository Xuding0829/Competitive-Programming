#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 110;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int root;
    std::vector<int> v(N), w(N), g[N];
    for (int i = 1, fa; i <= n; i++)
    {
        std::cin >> v[i] >> w[i] >> fa;
        if (fa == -1)
            root = i;
        else
            g[fa].push_back(i);
    }

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));

    std::function<void(int)> dfs = [&](int u)
    {
        for (int i = v[u]; i <= m; i++)
            f[u][i] = w[u];

        for (int i = 0; i < g[u].size(); i++)
        {
            int son = g[u][i];
            dfs(son);
            for (int j = m; j >= v[u]; j--)
                for (int k = 0; k <= j - v[u]; k++)
                    f[u][j] = std::max(f[u][j], f[u][j - k] + f[son][k]);
        }
    };

    dfs(root);

    std::cout << f[root][m] << '\n';
    return 0;
}