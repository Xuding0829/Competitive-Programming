#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 510, inf = 0x3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> m >> n;

    std::string line;
    getline(std::cin, line);

    std::vector<std::vector<int>> g(N, std::vector<int>(N));
    while (m--)
    {
        getline(std::cin, line);

        std::stringstream s;
        s << line;

        int p;
        std::vector<int> stop;
        while (s >> p)
            stop.push_back(p);

        // for (int i = 0; i < stop.size(); i++)
        //     std::cout << stop[i] << " ";
        // std::cout << '\n';

        for (int i = 0; i < stop.size(); i++)
            for (int j = i + 1; j < stop.size(); j++)
                g[stop[i]][stop[j]] = 1;
    }

    std::function<int(void)> bfs = [=]()
    {
        std::vector<int> dis(n + 1, inf);

        std::queue<int> q;
        q.push(1);
        dis[1] = 0;

        while (q.size())
        {
            int t = q.front();
            q.pop();

            for (int i = 1; i <= n; i++)
                if (g[t][i] && dis[i] > dis[t] + 1)
                    dis[i] = dis[t] + 1, q.push(i);
        }

        return dis[n];
    };

    int res = bfs();
    if (res == inf)
        std::cout << "NO\n";
    else
        std::cout << std::max(res - 1, 0) << '\n';

    return 0;
}