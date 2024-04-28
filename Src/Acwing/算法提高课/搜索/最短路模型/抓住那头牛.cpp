#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 10;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<bool> vis(N);

    auto bfs = [&]()
    {
        std::queue<std::pair<int, int>> q;
        q.push({n, 0});
        while (q.size())
        {
            auto [x, d] = q.front();
            q.pop();
            // std::cout << x << ' ' << d << '\n';

            if (x == k)
                return d;
            if (x + 1 <= N && x + 1 >= 0 && !vis[x + 1])
            {
                vis[x + 1] = true;
                q.push({x + 1, d + 1});
            }
            if (x - 1 <= N && x - 1 >= 0 && !vis[x - 1])
            {
                vis[x - 1] = true;
                q.push({x - 1, d + 1});
            }
            if (x * 2 <= N && x * 2 >= 0 && !vis[x * 2])
            {
                vis[x * 2] = true;
                q.push({x * 2, d + 1});
            }
        }
        return -1;
    };

    std::cout << bfs() << '\n';

    return 0;
}