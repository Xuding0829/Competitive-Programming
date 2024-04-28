#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int k, n;
    std::cin >> k >> n;

    std::vector<int> a(k);
    a[0] = 1;
    for (int i = 1; i < k; i++)
        a[i] = std::min(a[i - 1] + i - 1, n - k + 1);
    for (int i = 0; i < k; i++)
        a[i] += i;

    for (int i = 0; i < k; i++)
        std::cout << a[i] << " \n"[i == k - 1];
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