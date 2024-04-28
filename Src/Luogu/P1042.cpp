#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char c;
    std::vector<int> a;
    while (1)
    {
        std::cin >> c;
        if (c == 'E')
            break;
        else if (c == 'W')
            a.push_back(1);
        else if (c == 'L')
            a.push_back(0);
    }

    int comp[2] = {11, 21};
    for (int i = 0; i < 2; i++)
    {
        int l = 0, w = 0;
        for (auto it : a)
        {
            l += 1 - it, w += it;
            if (std::max(l, w) >= comp[i] && std::max(l, w) - std::min(l, w) >= 2)
            {
                std::cout << w << ':' << l << '\n';
                w = 0, l = 0;
            }
        }
        std::cout << w << ':' << l << '\n';
        std::cout << '\n';
    }

    return 0;
}