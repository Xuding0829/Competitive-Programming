#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(3);
    for (int i = 0; i < 3; i++)
        a[i] = n / 3;
    a[1]++, a[2]--;
    a[1] += n % 3;

    for (int i = 0; i < 3; i++)
        std::cout << a[i] << ' ';
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