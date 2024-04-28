#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        std::cin >> l[i];
    for (int i = 0; i < n; i++)
        std::cin >> r[i];

    int ans = 0x3f3f3f3f, cnt = 0, sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for (int i = 0; i < n; i++)
    {
        int len = r[i] - l[i] + 1;
        sum += len;
        q.push(len);
        while (sum >= k)
        {
            int rest = sum - k;
            int res = q.size() * 2 + l[i] + len - rest - 1;
            ans = std::min(res, ans);
            sum -= q.top();
            q.pop();
        }
    }
    std::cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
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