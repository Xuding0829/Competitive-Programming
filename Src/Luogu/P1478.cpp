#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;

    int a, b;
    std::cin >> a >> b;

    std::vector<std::pair<int, int>> apple;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (a + b < x)
            continue;
        apple.push_back({y, x});
    }
    std::sort(apple.begin(), apple.end());

    int res = 0;
    for (auto [y, x] : apple)
    {
        if (s >= y)
            s -= y, res++;
    }
    std::cout << res << '\n';

    return 0;
}