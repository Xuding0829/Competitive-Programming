#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n != m)
    {
        if (n == 1 || m == 1)
            std::cout << (n < m ? "Alice" : "Bob");
        else
            std::cout << (n > m ? "Alice" : "Bob");
    }
    else
        std::cout << "Draw";

    return 0;
}