#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 4e5 + 100;
int q[N], a[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[i] <= a[q[tt]])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            std::cout << a[q[hh]] << ' ';
    }

    std::cout << '\n';

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[i] >= a[q[tt]])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            std::cout << a[q[hh]] << ' ';
    }

    return 0;
}
/*
#include <bits/stdc++.h>
using i64 = long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
         std::cin >> a[i];
    std::deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && i - k + 1 > q.front())
             q.pop_front();
        while (!q.empty() && a[i] < a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
            std::cout << a[q.front()] << " \n"[i == n - 1];
    }
    q.clear();
    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && i - k + 1 > q.front())
            q.pop_front();
        while (!q.empty() && a[i] > a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
            std::cout << a[q.front()] << " \n"[i == n - 1];
    }
    return 0;
}
*/