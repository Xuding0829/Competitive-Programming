#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string end, start;
    for (int i = 0, x; i < 8; i++)
    {
        std::cin >> x;
        end += char('0' + x);
        start += char('1' + i);
    }

    std::map<std::string, int> dis;
    std::map<std::string, std::pair<char, std::string>> pre;
    auto move0 = [&](std::string t)
    {
        for (int i = 0; i < 4; i++)
            std::swap(t[i], t[7 - i]);
        return t;
    };
    auto move1 = [&](std::string t)
    {
        for (int i = 0; i < 3; i++)
            std::swap(t[3], t[i]);
        for (int i = 4; i < 7; i++)
            std::swap(t[i], t[i + 1]);
        return t;
    };
    auto move2 = [&](std::string t)
    {
        std::swap(t[1], t[2]), std::swap(t[5], t[6]), std::swap(t[1], t[5]);
        return t;
    };

    auto bfs = [&](std::string start, std::string end) -> void
    {
        std::queue<std::string> q;
        q.push(start);
        while (q.size())
        {
            auto s = q.front();
            q.pop();
            if (s == end)
                return;

            std::string m[3];
            m[0] = move0(s), m[1] = move1(s), m[2] = move2(s);
            for (int i = 0; i < 3; i++)
            {
                std::string t = m[i];
                if (dis.count(t) == 0)
                {
                    dis[t] = dis[s] + 1;
                    pre[t] = {'A' + i, s};
                    if (t == end)
                        return;
                    q.push(t);
                }
            }
        }
    };

    bfs(start, end);
    std::cout << dis[end] << '\n';

    std::string res;
    while (end != start)
    {
        res += pre[end].first;
        end = pre[end].second;
    }
    std::reverse(res.begin(), res.end());
    if (res.size())
        std::cout << res << '\n';
    return 0;
}