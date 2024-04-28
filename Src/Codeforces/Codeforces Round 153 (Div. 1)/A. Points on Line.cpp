#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    i64 res = 0;
    std::queue<int> q;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        q.push(x);
        while (q.size() && x - q.front() > d)
            q.pop();

        if (x - q.front() <= d)
        {
            i64 k = q.size() - 1;
            res += k * (k - 1) / 2;
        }
    }
    std::cout << res << '\n';
    return 0;
}