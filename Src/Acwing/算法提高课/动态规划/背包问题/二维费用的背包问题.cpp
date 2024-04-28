#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, V, M;
    std::cin >> n >> V >> M;

    std::vector<int> v(n + 1), m(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> m[i] >> w[i];

    std::vector<std::vector<int>> f(V + 1, std::vector<int>(M + 1));
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= v[i]; j--)
            for (int k = M; k >= m[i]; k--)
                f[j][k] = std::max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);

    std::cout << f[V][M] << '\n';
    return 0;
}