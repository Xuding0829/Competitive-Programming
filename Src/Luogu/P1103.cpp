#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

struct node
{
    int h, w;
    bool operator<(struct node &t)
    {
        return h < t.h;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> k;
    m = n - k;

    std::vector<node> book(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> book[i].h >> book[i].w;
    std::sort(book.begin(), book.end());

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, inf));
    // f[i, j]表示从前i本书中选择， 选择j本书的最小不整齐度
    for (int i = 1; i <= n; i++)
        f[i][1] = 0; // 只选择一本书， 不整齐度为0

    for (int i = 2; i <= n; i++)                      // 枚举当前到哪本书
        for (int j = 1; j < i; j++)                   // 当前书与哪本书相邻
            for (int k = 2; k <= std::min(i, m); k++) // 枚举选择书的数量
                f[i][k] = std::min(f[i][k], f[j][k - 1] + abs(book[j].w - book[i].w));

    int res = inf;
    for (int i = 1; i <= n; i++)
        res = std::min(res, f[i][m]); // 遍历f数组，找到保留m本书的最小不整齐度
    std::cout << res << '\n';

    return 0;
}