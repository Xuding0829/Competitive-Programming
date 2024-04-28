#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> fa(n);
    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        std::cin >> fa[i];
        fa[i]--;
        adj[fa[i]].push_back(i);
    }

    std::vector<int> res;
    std::vector<int> pre(n);
    pre[0] = -1;

    std::function<void(int)> dfs = [&](int u)
    {
        for (auto v : adj[u])
        {
            pre[v] = u;
            dfs(v);
        }
    };

    dfs(0);

    std::stack<int> stk;
    for (int i = n - 1; i != -1; i = pre[i])
        stk.push(i);

    while (stk.size())
        std::cout << stk.top() + 1 << ' ', stk.pop();

    return 0;
}