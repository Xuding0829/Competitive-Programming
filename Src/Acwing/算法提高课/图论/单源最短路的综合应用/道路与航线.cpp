#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f, N = 2e5 + 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, mr, mp, s;
    std::cin >> n >> mr >> mp >> s;

    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    // == std::vector<std::pair<int, int>> adj[n + 1] ?
    while (mr--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int cnt = 0;
    std::vector<int> id(n + 1);
    std::vector<int> block[n + 1];

    std::function<void(int)> dfs = [&](int u)
    {
        id[u] = cnt;
        block[cnt].push_back(u);

        for (auto [v, w] : adj[u]) // 遍历u相连的边且边的另一顶点是v
            if (!id[v])
                dfs(v);
    };

    for (int i = 1; i <= n; i++)
    {
        if (!id[i])
            ++cnt, dfs(i); // 计算每个顶点属于的连通块
    }

    std::vector<int> du(n + 1);
    while (mp--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        du[id[v]]++;
    }

    std::vector<int> dis(n + 1);
    std::queue<int> q;
    std::bitset<N> st;

    std::function<void(int)> dijkstra = [&](int block_id)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;

        for (auto i : block[block_id])
            h.push({dis[i], i});

        while (h.size())
        {
            auto t = h.top();
            h.pop();
            int u = t.second;

            if (st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (id[v] == block_id)
                        h.push({dis[v], v});
                }

                if (id[v] != block_id && --du[id[v]] == 0)
                    q.push(id[v]);
            }
        }
    };

    std::function<void(void)> topsort = [&]()
    {
        std::fill(dis.begin(), dis.end(), inf);
        dis[s] = 0;

        for (int i = 1; i <= cnt; i++)
            if (!du[i])
                q.push(i);

        while (q.size())
        {
            int t = q.front();
            q.pop();
            dijkstra(t);
        }
    };

    topsort();

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > inf / 2)
            std::cout << "NO PATH\n";
        else
            std::cout << dis[i] << '\n';
    }

    return 0;
}

/*
#include <bits/stdc++.h>

using i64 = long long;

const int N = 25100, M = 150010, inf = 0x3f3f3f3f;

int dis[N];
bool st[N];

int n, mr, mp, s;
int h[N], e[M], ne[M], w[M], idx;

int din[N], id[N], block_cnt;
std::vector<int> block[N];
std::queue<int> que;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    block[block_cnt].push_back(u);
    id[u] = block_cnt;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!id[j])
            dfs(j);
    }
}

void dijkstra(int block_id)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    for (auto i : block[block_id])
        q.push({dis[i], i});

    while (q.size())
    {
        int t = q.top().second;
        q.pop();

        if (st[t])
            continue;
        st[t] = true;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (id[j] == block_id)
                    q.push({dis[j], j});
            }

            if (id[j] != block_id && --din[id[j]] == 0)
                que.push(id[j]);
        }
    }
}

void topsort()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    for (int i = 1; i <= block_cnt; i++)
    {
        if (!din[i])
            que.push(i);
    }

    while (que.size())
    {
        int t = que.front();
        que.pop();
        dijkstra(t);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    std::cin >> n >> mr >> mp >> s;

    while (mr--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    for (int i = 1; i <= n; i++)
        if (!id[i])
            ++block_cnt, dfs(i);

    while (mp--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(u, v, w);
        din[id[v]]++;
    }

    topsort();

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > inf / 2)
            std::cout << "NO PATH\n";
        else
            std::cout << dis[i] << '\n';
    }

    return 0;
}*/