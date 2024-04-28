#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    std::sort(p.begin(), p.end());

    int sum = 1;
    for (int i = 1; i < n; i++)
        if (p[i] == p[i - 1])
            sum++;
    std::cout << sum << '\n';

    return 0;
}