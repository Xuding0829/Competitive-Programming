#include <bits/stdc++.h>

using i64 = long long;

const int N = 6010;

int idx;
std::bitset<N> has_father;
std::vector<int> h(N, -1), e(N), ne(N);
std::vector<int> happy(N);
std::vector<std::vector<int>> f(N, std::vector<int>(2));

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += std::max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> happy[i];

    for (int i = 1; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        has_father[a] = true;
        add(b, a);
    }

    int root = 1;
    while(has_father[root])
        root++;
    
    dfs(root);

    std::cout << std::max(f[root][1], f[root][0]) << '\n';
    return 0;
}