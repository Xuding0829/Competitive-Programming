#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<int> a;
    while (std::cin >> x && x)
        a.push_back(x);
    std::reverse(a.begin(), a.end());
    for (auto i : a)
        std::cout << i << ' ';
    return 0;
}