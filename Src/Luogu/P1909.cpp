#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> pen(3);
    for (int i = 0; i < 3; i++)
        std::cin >> pen[i].first >> pen[i].second;

    int sum = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++)
        sum = std::min(sum, (int)ceil(n * 1.0 / pen[i].first) * pen[i].second);

    std::cout << sum << '\n';
    return 0;
}