#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= a[k - 1] && a[i])
            res++;

    std::cout << res << '\n';

    return 0;
}