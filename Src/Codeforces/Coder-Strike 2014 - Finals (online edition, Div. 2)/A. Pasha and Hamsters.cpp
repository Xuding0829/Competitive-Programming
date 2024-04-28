#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> apple(n + 1);
    for (int i = 1, x; i <= a; i++)
    {
        std::cin >> x;
        apple[x] = 1;
    }
    for (int i = 1, x; i <= b; i++)
    {
        std::cin >> x;
        if (apple[x] != 1)
            apple[x] = 2;
    }

    for (int i = 1; i <= n; i++)
        std::cout << apple[i] << ' ';
    std::cout << '\n';

    return 0;
}