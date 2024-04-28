#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int inf = 0x3f3f3f3f;

int n, m;
std::vector<std::pair<int, int>> adj[1010];
std::vector<int> dis(1010, inf);
std::vector<bool> st(1010);

int dijkstra()
{
    dis[0] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
    h.push(std::make_pair(0, 0));
    while (h.size())
    {
        int u = h.top().second;
        h.pop();

        if (st[u])
            continue;
        st[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                h.push(std::make_pair(dis[v], v));
            }
        }
    }
    return dis[n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w));
    }

    std::cout << dijkstra() << '\n';
    return 0;
}