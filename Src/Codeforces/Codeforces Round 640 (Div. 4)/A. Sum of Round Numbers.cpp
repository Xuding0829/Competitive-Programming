#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a;
    int tmp = n, k = 0;
    while (tmp)
    {
        int m = tmp % 10;
        a.push_back(m);
        tmp /= 10;
        k++;
    }

    int res = 0;
    for (int i = 0; i < k; i++)
    {
        a[i] = a[i] * pow(10, i);
        if (a[i])
            res++;
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    std::cout << res << '\n';
    for (auto it : a)
        if (it)
            std::cout << it << ' ';
    std::cout << '\n';
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