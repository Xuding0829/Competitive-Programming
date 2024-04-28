#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    while (m--)
    {
        int x;
        std::cin >> x;
        x--;
        std::cout << a[x] << '\n';
    }

    return 0;
}