#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < a.size() + b.size(); i++)
    {
        if (i % 2 == 0)
            std::cout << a[cnt1++];
        else
            std::cout << b[cnt2++];
    }

    return 0;
}