#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m && n | m)
    {
        std::bitset<(1 << 12)> st;
        for (int i = 0; i < (1 << n); i++)
        {
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    if (cnt & 1)
                    {
                        st[i] = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                st[i] = false;
        }

        std::vector<std::vector<i64>> f(13, std::vector<i64>(1 << 12));
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < (1 << n); j++)
                for (int k = 0; k < (1 << n); k++)
                    if ((j & k) == 0 && st[j | k])
                        f[i][j] += f[i - 1][k];
        std::cout << f[m][0] << '\n';
    }

    return 0;
}