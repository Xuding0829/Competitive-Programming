#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> len(n);
    for (int i = 0; i < n; i++)
        std::cin >> len[i];

    auto check = [&](int mid)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += len[i] / mid;
        return cnt >= k;
    };

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << '\n';

    return 0;
}