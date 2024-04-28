#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> a(100, std::vector<char>(100)), b(100, std::vector<char>(100));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            std::cin >> b[i][j];

    bool is_same = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == b[0][0])
            {
                is_same = true;
                for (int x = 0; x < m; x++)
                    for (int y = 0; y < m; y++)
                    {
                        if (a[i + x][j + y] != b[x][y])
                        {
                            is_same = false;
                            break;
                        }
                    }
            }
            if (is_same)
            {
                std::cout << "Yes";
                return 0;
            }
        }

    std::cout << "No";
    return 0;
}