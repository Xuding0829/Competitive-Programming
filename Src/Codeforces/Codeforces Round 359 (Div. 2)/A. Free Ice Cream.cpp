#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, x;
    std::cin >> n >> x;

    int distress = 0;
    while (n--)
    {
        char op;
        int num;
        std::cin >> op >> num;

        if (op == '+')
            x += num;
        else
        {
            if (x < num)
                distress++;
            else
                x -= num;
        }
    }
    std::cout << x << ' ' << distress << '\n';

    return 0;
}