#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int sum = 0;
    for (int i = 1;; i++)
    {
        sum += i;
        if (sum >= n)
        {
            std::cout << i << '\n';
            return 0;
        }
    }

    return 0;
}