#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int h, m, x;
    scanf("%d:%d %d", &h, &m, &x);

    int time = h * 60 + m, res = 0;
    int k = time;

    while (1)
    {
        int th = time / 60 % 24, tm = time % 60;

        std::string t1, t2;
        if (th / 10 == 0)
            t1 = '0';
        t1 += std::to_string(th);
        if (tm / 10 == 0)
            t2 = '0';
        t2 += std::to_string(tm);

        if (t1[0] == t2[1] && t1[1] == t2[0])
            res++;

        (time += x) %= 1440;
        if (time == k)
            break;
    }
    std::cout << res << '\n';
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}