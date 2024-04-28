#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> res;
    for (int i = 0; i < (1 << n); i++)
        res.push_back(i ^ (i >> 1));

    auto print = [&](int x) -> void
    {
        std::string t;
        while (x)
        {
            t = (x % 2 == 0 ? '0' : '1') + t;
            x /= 2;
        }

        while (t.size() < n)
            t = '0' + t;
        std::cout << t << '\n';
    };

    for (int i = 0; i < (1 << n); i++)
        print(res[i]);

    return 0;
}