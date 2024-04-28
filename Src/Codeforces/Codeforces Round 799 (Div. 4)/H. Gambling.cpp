#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        mp[a[i]].push_back(i);
    }

    /*
    首先我们可以得到一个性质，这个区间的左右端点必然是赢钱的，不然就会莫名其妙亏了，然后呢这个问题的本质就是问你
    区间内众数-非众数的个数最大是多少。
    那么我们可以记录每一个元素出现的位置，用map> 来存储，vector是a，位置下标数组
    然后我们去遍历这个map,固定了一个右端点ai，我们则可以发现，这个答案就是(i -j + 1)- (a[i] - a[j] + 1 - (i - j + 1)
    == 2i - ai + 1 + aj - 2j,后面的j是不固定的
    */

    int res = a[0], l = 0, r = 0, mx = 0;
    for (auto [u, q] : mp)
    {
        int t = -0x3f, j;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] - 2 * i > t)
                t = q[i] - 2 * i, j = q[i];

            int cur = 2 * i - q[i] + 1 + t;

            if (cur > mx)
                mx = cur, res = u, l = j + 1, r = q[i] + 1;
        }
    }
    std::cout << res << ' ' << l << ' ' << r << '\n';
}

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