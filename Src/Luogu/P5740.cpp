#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string name[1005];
    int cg[1005], mg[1005], eg[1005];
    int n, max = -999999, t;
    std::cin >> n;
    for (int a = 0; a < n; a++)
        std::cin >> name[a] >> cg[a] >> mg[a] >> eg[a];
    for (int b = 0; b < n; b++)
    {
        if (cg[b] + mg[b] + eg[b] > max)
        {
            max = cg[b] + mg[b] + eg[b];
            t = b;
        }
    }
    std::cout << name[t] << " " << cg[t] << " " << mg[t] << " " << eg[t];

    return 0;
}