#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m + 2; i++)
        std::cout << "#";
    std::cout << '\n';

    for (int i = 0; i < n; i++)
        std::cout << "#" << a[i] << "#\n";

    for (int i = 0; i < m + 2; i++)
        std::cout << "#";
    std::cout << '\n';
    return 0;
}