#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int i, high, water;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string s[2];
    std::cin >> s[0] >> s[1];
    s[0] = ' ' + s[0];
    s[1] = ' ' + s[1];
    auto bfs = [&]()
    {
        std::queue<node> q;
        q.push({0, 1, 0});
        s[0][1] = 'X';
        while (q.size())
        {
            auto [id, high, water] = q.front();
            q.pop();

            if (high + 1 > n)
                return true;

            if (s[id][high + 1] != 'X' && high + 1 > water + 1)
            {
                s[id][high + 1] = 'X';
                q.push({id, high + 1, water + 1});
            }

            if (high - 1 > 0 && s[id][high - 1] != 'X' && high - 1 > water + 1)
            {
                s[id][high - 1] = 'X';
                q.push({id, high - 1, water + 1});
            }

            if (high + k > n)
                return true;
            if (s[1 - id][high + k] != 'X' && high + k > water + 1)
            {
                s[1 - id][high + k] = 'X';
                q.push({1 - id, high + k, water + 1});
            }
        }
        return false;
    };
    std::cout << (bfs() ? "YES\n" : "NO\n");
    return 0;
}