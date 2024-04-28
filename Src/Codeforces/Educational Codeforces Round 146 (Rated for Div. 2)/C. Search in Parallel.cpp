#include <bits/stdc++.h>

using i64 = long long;

struct node
{
    int times, col;
    bool operator<(const node &t)
    {
        return times > t.times;
    }
};

void solve()
{
    int n, s1, s2;
    std::cin >> n >> s1 >> s2;

    std::vector<node> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i].times, a[i].col = i;
    std::sort(a.begin(), a.end());

    int t1 = 0, t2 = 0;
    std::vector<int> res1, res2;
    for (int i = 0; i < n; i++)
    {
        if (t1 + s1 <= t2 + s2)
            res1.push_back(a[i].col + 1), t1 += s1;
        else
            res2.push_back(a[i].col + 1), t2 += s2;
    }

    std::cout << res1.size() << ' ';
    for (int i = 0; i < res1.size(); i++)
        std::cout << res1[i] << ' ';
    std::cout << '\n';
    std::cout << res2.size() << ' ';
    for (int i = 0; i < res2.size(); i++)
        std::cout << res2[i] << ' ';
    std::cout << '\n';
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