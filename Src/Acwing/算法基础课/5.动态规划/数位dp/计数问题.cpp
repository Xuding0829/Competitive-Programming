#include <bits/stdc++.h>

using i64 = long long;

i64 count(int n, int x) // 1-n中x出现的次数
{
    // abcdefg
    int m = n;
    std::vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    int cnt = num.size();

    i64 res = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int p = pow(10, i - 1), l = m / p / 10, r = m % p, tmp = m / p % 10;

        if (x)
            res += l * p;
        else
            res += (l - 1) * p;

        if (tmp > x)
            res += p;
        else if (tmp == x)
            res += r + 1;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    while (std::cin >> a >> b, a || b)
    {
        if (a > b)
            std::swap(a, b);
        for (int i = 0; i < 10; i++)
            std::cout << count(b, i) - count(a - 1, i) << " ";
        std::cout << '\n';
    }

    return 0;
}