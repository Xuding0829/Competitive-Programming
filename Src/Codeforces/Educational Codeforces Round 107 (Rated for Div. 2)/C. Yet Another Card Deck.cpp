#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n + 1);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    while (q--)
    {
        int t;
        std::cin >> t;

        int pos, tmp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == t)
            {
                pos = i;
                break;
            }
        }
        std::cout << pos + 1 << ' ';
        for (int i = pos; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = t;
    }
    return 0;
}