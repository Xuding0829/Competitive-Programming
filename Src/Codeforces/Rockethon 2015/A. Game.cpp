#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n1, n2;
    std::cin >> n1 >> n2;
    std::cout << (n1 > n2 ? "First\n" : "Second\n");

    return 0;
}