#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::map<int, int> mp;
    while (q--)
    {
        int op;
        std::cin >> op;

        int i, j, k;
        if (op == 1)
        {
            std::cin >> i >> j >> k;
            mp[i * 1000000 + j] = k;
        }
        else
        {
            std::cin >> i >> j;
            std::cout << mp[i * 1000000 + j] << '\n';
        }
    }

    return 0;
}