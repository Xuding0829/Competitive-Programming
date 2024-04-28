#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n % 2 == 0)
        std::cout << "0\n";
    else
    {
        int res = 0, tmp = n, k = 0;

        std::vector<int> a(10), b(10);
        while (tmp)
        {
            int m = tmp % 10;
            a[m]++, tmp /= 10, k++;
        }

        if (!a[2] && !a[4] && !a[6] && !a[8])
            std::cout << "-1\n";
        else
        {
            for (int i = 0; i < k; i++)
                tmp = n % 10, b[i] = tmp, n /= 10;

            if (b[k - 1] % 2 == 0)
                std::cout << "1\n";
            else
                std::cout << "2\n";
        }
    }
}

// 更简洁的写法：记录偶数出现的位置，如果是最高位则1，不是则2
/*
    if(n % 2 == 0) cout << 0 << endl;
    else
    {
        int cnt = 0;
        int x = 0;
        while(n)
        {
            a[++cnt] = n%10;
            if(a[cnt] % 2 == 0) x = cnt;
            n/=10;
        }
        if(x == 0) cout << "-1" << endl;
        else
        {
            if(x == cnt) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}