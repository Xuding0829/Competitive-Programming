#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::deque<i64> q;
    std::vector<bool> vis(n);
    std::vector<i64> a(n);
    std::set<i64> st;
    std::map<i64, i64> mp;
    for (int i = 0; i < n; i++)
        std::cin >> a[i], st.insert(a[i]), mp[a[i]] = i;
    std::sort(a.begin(), a.end());

    i64 t = *std::min_element(a.begin(), a.end());
    q.push_front(t), vis[mp[t]] = true;

    for (int i = 0; i < n; i++)
    {
        t = q.back();
        while (st.count(t * 2) && !vis[mp[t * 2]])
        {
            q.push_back(t * 2);
            t *= 2, vis[mp[t]] = true;
        }

        t = q.back();
        while (st.count(t / 3) && !vis[mp[t / 3]])
        {
            q.push_back(t / 3);
            t /= 3, vis[mp[t]] = true;
        }

        t = q.front();
        while (st.count(t * 3) && !vis[mp[t * 3]])
        {
            q.push_front(t * 3);
            t *= 3, vis[mp[t]] = true;
        }

        t = q.front();
        while (st.count(t / 2) && !vis[mp[t / 2]])
        {
            q.push_front(t / 2);
            t /= 2, vis[mp[t]] = true;
        }
    }

    while (q.size())
    {
        std::cout << q.front() << ' ';
        q.pop_front();
    }

    return 0;
}