#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;
std::pair<i64, int> a[N], b[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int t1 = 0, t2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        std::cin >> t >> p;
        if (t == 1)
            a[++t1].first = p, a[t1].second = i;
        else
            b[++t2].first = p, b[t2].second = i;
    }

    std::sort(a + 1, a + t1 + 1, std::greater<>());
    std::sort(b + 1, b + t2 + 1, std::greater<>());

    for (int i = 1; i <= t1; i++)
        a[i].first += a[i - 1].first;
    for (int i = 1; i <= t2; i++)
        b[i].first += b[i - 1].first;

    i64 ans = 0, posa = 0, posb = 0;
    for (int i = 0; i <= std::min(t1, m); i++)
    {
        int j = std::min(t2, (m - i) >> 1);
        if (a[i].first + b[j].first > ans)
            ans = a[i].first + b[j].first, posa = i, posb = j;
    }

    std::cout << ans << '\n';
    for (int i = 1; i <= posa; i++)
        std::cout << a[i].second << ' ';
    for (int i = 1; i <= posb; i++)
        std::cout << b[i].second << ' ';
    return 0;
}