#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, p;
    std::cin >> s >> p;

    std::vector<int> ne(p.size() + 1);
    for (int i = 2, j = 0; i < p.size() + 1; i++)
    {
        while (j && p[i - 1] != p[j])
            j = ne[j];
        if (p[i - 1] == p[j])
            j++;
        ne[i] = j;
    }

    for (int i = 0, j = 0; i < s.size(); i++)
    {
        while (j && s[i] != p[j])
            j = ne[j];
        if (s[i] == p[j])
            j++;
        if (j == p.size())
        {
            std::cout << i - j + 2 << '\n';
            j = ne[j];
        }
    }

    for (int i = 1; i <= p.size(); i++)
        std::cout << ne[i] << ' ';
    return 0;
}