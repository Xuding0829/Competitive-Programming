#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    while (std::cin >> t)
    {
        int cnt = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> h[5];

        for (int i = 0; i < t; i++)
        {
            int a, b;
            std::string op;
            std::cin >> op;

            if (op == "IN")
            {
                cnt++;
                std::cin >> a >> b;
                h[a].push({b, -cnt});
            }
            else
            {
                std::cin >> a;
                if (h[a].size())
                {
                    int id = -h[a].top().second;
                    h[a].pop();
                    std::cout << id << "\n";
                }
                else
                    std::cout << "EMPTY\n";
            }
        }
    }

    return 0;
}