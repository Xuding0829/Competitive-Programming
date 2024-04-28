#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d, sumtime;
    std::cin >> d >> sumtime;

    int suml = 0, sumr = 0;
    std::vector<int> l(d), r(d);
    for (int i = 0; i < d; i++)
        std::cin >> l[i] >> r[i], suml += l[i], sumr += r[i];

    if (suml > sumtime || sumr < sumtime)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        if (sumr == sumtime)
        {
            for (int i = 0; i < d; i++)
                std::cout << r[i] << ' ';
        }
        else
        {
            sumtime -= suml;
            for (int i = 0; i < d; i++)
            {
                if (sumtime >= r[i] - l[i])
                {
                    sumtime -= r[i] - l[i];
                    l[i] += r[i] - l[i];
                }
                else
                    l[i] += sumtime, sumtime -= sumtime;
            }

            for (int i = 0; i < d; i++)
                std::cout << l[i] << ' ';
        }
    }

    return 0;
}