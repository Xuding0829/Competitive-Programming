#include <bits/stdc++.h>

using i64 = long long;
struct coin
{
    int w, v;
    double x;
    bool operator<(const coin &t) const
    {
        return x > t.x;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double n, m;
    std::cin >> n >> m;

    std::vector<coin> a(n);
    for (int i = 0; i < n; i++)
    {
        int w, v;
        std::cin >> w >> v;
        a[i] = {w, v, v * 1.0 / w};
    }
    std::sort(a.begin(), a.end());

    double res = 0;
    for (auto [u, v, w] : a)
    {
        if (m >= u)
            m -= u, res += v;
        else
        {
            res += m * w;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << res << '\n';
    return 0;
}