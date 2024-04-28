#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 32100;

bool is_main[70];
std::vector<int> v(70), w(70), group[70];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1, st; i <= m; i++)
    {
        std::cin >> v[i] >> w[i] >> st;
        w[i] *= v[i];
        if (st)
            group[st].push_back(i);
        else
            is_main[i] = true;
    }

    std::vector<int> f(N);
    for (int i = 1; i <= m; i++)
    {
        if (is_main[i])
        {
            for (int j = n; j >= 0; j--)
            {
                int siz = group[i].size();
                for (int st = 0; st < (1 << siz); st++)
                {
                    int v_sum = v[i], w_sum = w[i];

                    for (int k = 0; k < siz; k++)
                        if (st >> k & 1)
                            v_sum += v[group[i][k]], w_sum += w[group[i][k]];

                    if (j >= v_sum)
                        f[j] = std::max(f[j], f[j - v_sum] + w_sum);
                }
            }
        }
    }

    std::cout << f[n] << '\n';

    return 0;
}