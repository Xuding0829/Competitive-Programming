#include<bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        int num;
        while (temp)
        {
            num = temp % 10;
            if (num == x)
                sum++;
            temp /= 10;
        }
    }
    std::cout << sum << '\n';

    return 0;
}