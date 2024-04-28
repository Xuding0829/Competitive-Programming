#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5;
int next[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
        next[i] = i + 1;
    next[n] = 1;

    for (int i = 1, p = 0; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
            p = next[p];
        std::cout << next[p] << ' ';
        next[p] = next[next[p]];
    }

    return 0;
}