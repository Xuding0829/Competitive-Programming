#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int res = 0;
    std::vector<int> a;
    for (int i = 0, x; i < m; i++)
    {
        std::cin >> x;
        if (std::find(a.begin(), a.end(), x) == a.end())
            res++, a.push_back(x);
        if (a.size() > n)
            a.erase(a.begin());
    }
    std::cout << res << '\n';

    return 0;
}