#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i & 1)
                std::cout << '#';
            else
            {
                if ((i / 2) & 1 == 1 && j == m)
                    std::cout << '#';
                else if ((i / 2) % 2 == 0 && j == 1)
                    std::cout << '#';
                else
                    std::cout << '.';
            }
        }
        std::cout << '\n';
    }

    return 0;
}