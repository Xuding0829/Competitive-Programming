#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, s;
    std::cin >> k >> s;

    int res = 0;
    for (int x = 0; x <= k; x++)
        for (int y = 0; y <= k; y++)
        {
            int z = s - x - y;
            if (z >= 0 && z <= k)
                res++;
        }

    std::cout << res << '\n';
    return 0;
}