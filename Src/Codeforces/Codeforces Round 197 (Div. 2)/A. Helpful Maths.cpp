#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::vector<int> a;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '+')
            a.push_back(s[i] - '0');

    std::sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        if (i != a.size() - 1)
            std::cout << a[i] << '+';
        else
            std::cout << a[i] << '\n';
    }

    return 0;
}