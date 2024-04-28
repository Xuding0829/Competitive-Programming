#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    std::vector g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            std::string a = s[i], b = s[j];
            for (int k = 1; k < std::min(a.size(), b.size()); k++)
            {
                if (a.substr(a.size() - k, k) == b.substr(0, k))
                {
                    g[i][j] = k;
                    break;
                }
            }
        }

    int res = 0;
    std::vector<int> used(n);
    std::function<void(std::string, int)> dfs = [&](std::string str, int last)
    {
        res = std::max(res, (int)str.size());
        used[last]++;
        for (int i = 0; i < n; i++)
        {
            if (g[last][i] && used[i] < 2)
                dfs(str + s[i].substr(g[last][i]), i);
        }
        used[last]--;
    };

    char ch;
    std::cin >> ch;

    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == ch)
            dfs(s[i], i);
    }
    std::cout << res << '\n';

    return 0;
}