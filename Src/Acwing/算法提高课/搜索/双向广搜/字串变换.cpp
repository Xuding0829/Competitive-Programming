#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string A, B;
    std::cin >> A >> B;

    std::vector<std::string> a, b;
    std::string u, v;
    while (std::cin >> u >> v)
        a.push_back(u), b.push_back(v);
    int n = a.size();

    std::unordered_map<std::string, int> da, db;
    std::queue<std::string> qa, qb;

    auto extend = [&](std::queue<std::string> &q, std::unordered_map<std::string, int> &da, std::unordered_map<std::string, int> &db, std::vector<std::string> a, std::vector<std::string> b)
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (t.substr(i, a[j].size()) == a[j])
                {
                    std::string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                    if (db.count(state))
                        return da[t] + 1 + db[state];
                    if (da.count(state))
                        continue;
                    da[state] = da[t] + 1;
                    q.push(state);
                }
            }
        }
        return 11;
    };

    auto bfs = [&](std::string A, std::string B)
    {
        if (A == B)
            return 0;
        da[A] = 0, db[B] = 0;
        qa.push(A), qb.push(B);

        while (qa.size() && qb.size())
        {
            int t;
            if (qa.size() <= qb.size())
                t = extend(qa, da, db, a, b);
            else
                t = extend(qb, db, da, b, a);
            if (t <= 10)
                return t;
        }
        return 11;
    };

    int step = bfs(A, B);
    if (step > 10)
        std::cout << "NO ANSWER!\n";
    else
        std::cout << step << '\n';

    return 0;
}