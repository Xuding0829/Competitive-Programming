#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, r;
    std::cin >> k >> r;

    for (int i = 1;; i++)
    {
        if ((i * k) % 10 == 0 || (i * k - r) % 10 == 0)
        {
            std::cout << i << '\n';
            break;
        }
    }

    return 0;
}