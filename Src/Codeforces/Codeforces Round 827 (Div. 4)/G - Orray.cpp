#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> b;
    std::vector<bool> st(n);

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int mx = cur, k = -1;
        for (int j = 0; j < n; j++)
        {
            int tmp = a[j] | cur;
            if (!st[j] && tmp > mx)
            {
                k = j;
                mx = tmp;
            }
        }

        if (k < 0)
            break;

        st[k] = true;
        b.push_back(a[k]);
        cur |= a[k];
    }

    for (int i = 0; i < n; i++)
        if (!st[i])
            b.push_back(a[i]);

    for (int i = 0; i < n; i++)
        std::cout << b[i] << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}