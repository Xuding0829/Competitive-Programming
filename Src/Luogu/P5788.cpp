#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &v : a)
        std::cin >> v;

    std::vector<int> f(n);
    std::stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() && a[s.top()] <= a[i])
            s.pop();
        f[i] = s.size() ? s.top() : -1;
        s.push(i);
    }

    for (auto i : f)
        std::cout << i + 1 << ' ';

    return 0;
}