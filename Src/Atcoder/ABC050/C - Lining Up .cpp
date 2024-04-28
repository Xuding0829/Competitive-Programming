#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

// 判断输入是否合法，不合法为0，否则为

i64 qmi(i64 a, i64 b, i64 p)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
} // 注意爆int

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0, x; i < n; i++)
        std::cin >> x, a[x]++;

    if (n & 1) // 奇数个人
    {
        if (a[0] != 1) // 奇数个人满足只有一个人为0
        {
            std::cout << "0\n";
            return 0;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (!(i & 1) && a[i] != 2) // 奇数个人时，下标为偶数的人为2
                {
                    std::cout << "0\n";
                    return 0;
                }
                else if (i & 1 && a[i]) // 奇数个人时，下标奇数的人为0
                {
                    std::cout << "0\n";
                    return 0;
                }
            }
        }
    }
    else // 偶数个人
    {
        if (a[0]) // 偶数个人，下标为0的人不存在
        {
            std::cout << "0\n";
            return 0;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (i & 1 && a[i] != 2) // 偶数个人，数组中下标为偶数的值不存在
                {
                    std::cout << "0\n";
                    return 0;
                }
                else if (!(i & 1) && a[i]) // 偶数个人，数组中下标为奇数的为2
                {
                    std::cout << "0\n";
                    return 0;
                }
            }
        }
    }

    std::cout << qmi(2, n / 2, mod) << "\n";
    return 0;
}