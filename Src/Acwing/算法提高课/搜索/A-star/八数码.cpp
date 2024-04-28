#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string start, s;
    char ch;
    for (int i = 0; i < 9; i++)
    {
        std::cin >> ch;
        start += ch;
        if (ch != 'x')
            s += ch;
    }

    auto f = [&](std::string s)
    {
        int tmp = 0;
        for (int i = 0; i < 9; i++)
        {
            if (s[i] == 'x')
                continue;
            int t = s[i] - '1';
            tmp += std::abs(i / 3 - t / 3) + std::abs(i % 3 - t % 3);
        }
        return tmp;
    };

    auto astar = [&]()
    {
        std::string ed = "12345678x";
        std::unordered_map<std::string, int> dis;
        std::unordered_map<std::string, std::pair<char, std::string>> pre;
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> q;
        dis[start] = 0;
        q.push({f(start), start});
        while (q.size())
        {
            auto [d, state] = q.top();
            q.pop();

            if (state == ed)
                break;

            int x = state.find('x') / 3, y = state.find('x') % 3;
            std::string source = state;
            char op[] = {'r', 'd', 'l', 'u'};
            int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= 3 || b < 0 || b >= 3)
                    continue;
                std::swap(state[a * 3 + b], state[x * 3 + y]);
                if (!dis.count(state) || dis[state] > dis[source] + 1)
                {
                    dis[state] = dis[source] + 1;
                    pre[state] = {op[i], source};
                    q.push({dis[state] + f(state), state});
                }
                state = source;
            }
        }

        std::string res;
        while (ed != start)
        {
            res = pre[ed].first + res;
            ed = pre[ed].second;
        }
        return res;
    };

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i; j < 8; j++)
            if (s[i] > s[j])
                cnt++;

    if (cnt & 1)
        std::cout << "unsolvable\n";
    else
        std::cout << astar() << '\n';

    return 0;
}