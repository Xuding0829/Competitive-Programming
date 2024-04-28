#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 cnt = 0, cur = 0;
    std::priority_queue<i64> q;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            cnt++, cur += a[i];
        else
        {
            if (a[i] + cur >= 0)
            {
                cnt++;
                cur += a[i];
                q.push(-a[i]);
            }
            else
            {
                if (q.size() && -a[i] <= q.top())
                {
                    cur += q.top() + a[i];
                    q.pop();
                    q.push(-a[i]);
                }
            }
        }
    }
    std::cout << cnt << '\n';

    return 0;
}