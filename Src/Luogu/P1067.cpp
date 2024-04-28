#include <bits/stdc++.h>

using i64 = long long;

/*
1号坑：开头如果为正则不输出符号

2号坑：系数为1或-1时只输出符号不输出系数

3号坑：系数为0时不输出该项

4号坑：一次项不要输出系数
*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = n, x; i >= 0; i--)
    {
        std::cin >> x;
        if (x)
        {
            if (i != n && x > 0)
                std::cout << '+';
            if (abs(x) > 1 || i == 0)
                std::cout << x;
            if (x == -1 && i)
                std::cout << '-';

            if (i > 1)
                std::cout << "x^" << i;
            if (i == 1)
                std::cout << 'x';
        }
    }

    return 0;
}