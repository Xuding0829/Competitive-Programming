#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n)
    {
        int k = 1;
        std::vector<int> path(110);
        path[0] = 1;
        std::function<bool(int, int)> dfs = [&](int u, int k)
        {
            if (u == k)
                return path[k - 1] == n;
            std::vector<bool> vis(110);
            for (int i = u - 1; i >= 0; i--)
                for (int j = i; j >= 0; j--)
                {
                    int s = path[i] + path[j];
                    if (vis[s] || s > n || s <= path[u - 1])
                        continue;
                    vis[s] = true;
                    path[u] = s;
                    if (dfs(u + 1, k))
                        return true;
                }
            return false;
        };
        while (!dfs(1, k))
            k++;
        for (int i = 0; i < k; i++)
            std::cout << path[i] << " \n"[i == k - 1];
    }

    return 0;
}