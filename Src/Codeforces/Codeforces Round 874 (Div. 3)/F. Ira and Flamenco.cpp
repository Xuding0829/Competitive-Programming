#include <bits/stdc++.h>

using i64 = unsigned long long;

const i64 mod = 1e9 + 7;

i64 qmi(i64 a, i64 b, i64 p)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1)
            res = (i64)res * a % p;
        a = (i64)a * a % p;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> cnt;
    for (int i = 0, x; i < n; i++)
        std::cin >> x, cnt[x]++;

    std::vector<std::pair<int, int>> v;
    for (auto x : cnt)
        v.push_back(x);
    std::sort(v.begin(), v.end());

    n = v.size();

    i64 res = 0, tmp = 1;
    for (int i = 0, j = 0; i < n;)
    {
        while (j < n && v[j].first < v[i].first + m)
            tmp = (i64)tmp * v[j++].second % mod;
        if (j - i == m)
            res = (res + tmp) % mod;
        tmp = (i64)tmp * qmi(v[i++].second, mod - 2, mod) % mod;
    }
    std::cout << res << '\n';
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