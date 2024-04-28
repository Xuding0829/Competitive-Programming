#include <iostream>
#include <string>
#include <vector>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> s(n), p(m);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    for (int i = 0; i < m; i++)
        std::cin >> p[i];

    std::vector<int> ne(m + 1);
    for (int i = 2, j = 0; i < m + 1; i++)
    {
        while (j && p[i - 1] != p[j])
            j = ne[j];
        if (p[i - 1] == p[j])
            j++;
        ne[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != p[j])
            j = ne[j];
        if (s[i] == p[j])
            j++;
        if (j == m)
        {
            std::cout << i - j + 2 << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}