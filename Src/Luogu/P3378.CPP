#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int, std::vector<int>, std::greater<int>> h;

    int t;
    std::cin >> t;
    while (t--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int x;
            std::cin >> x;
            h.push(x);
        }
        else if (op == 2 && h.size())
            std::cout << h.top() << '\n';
        else if (op == 3 && h.size())
            h.pop();
    }
    return 0;
}