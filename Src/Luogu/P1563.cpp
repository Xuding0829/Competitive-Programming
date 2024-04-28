#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, std::string>> stu(n);
    for (int i = 0; i < n; i++)
        std::cin >> stu[i].first >> stu[i].second;

    int cur = 0;
    while (m--)
    {
        int a, s;
        std::cin >> a >> s;

        if (a == 0) // 左数
        {
            if (stu[cur].first == 0)
                (cur += n - s) %= n;
            else
                (cur += s) %= n;
        }
        else // 右数
        {
            if (stu[cur].first == 0)
                (cur += s) %= n;
            else
                (cur += n - s) %= n;
        }
    }
    std::cout << stu[cur].second << '\n';
    return 0;
}