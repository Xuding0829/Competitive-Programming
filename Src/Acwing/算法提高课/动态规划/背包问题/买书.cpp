#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> price;
    price = {10, 20, 50, 100};

    std::vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j <= n; j++)
            if (j >= price[i])
                f[j] += f[j - price[i]];
    std::cout << f[n] << '\n';

    return 0;
}