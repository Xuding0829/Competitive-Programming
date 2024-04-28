#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, s, max = 0, i, day = 0;
    for (i = 1; i <= 7; i++)
    {
        std::cin >> a >> b;
        s = a + b;
        if ((s > max) && (s > 8))
            max = s, day = i;
    }
    std::cout << day;
    return 0;
}