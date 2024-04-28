#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int cnt = 0;
    std::vector<int> v, w;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        std::cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v.emplace_back(a * k);
            w.emplace_back(b * k);
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v.emplace_back(a * s);
            w.emplace_back(b * s);
        }
    }

    n = cnt;
    std::vector<int> f(m + 1);
    for (int i = 0; i < cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);

    std::cout << f[m] << '\n';
    return 0;
}