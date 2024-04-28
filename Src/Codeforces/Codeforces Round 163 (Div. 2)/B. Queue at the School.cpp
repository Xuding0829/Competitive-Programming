#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;

    std::string s;
    std::cin >> s;

    while (t--)
    {
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                std::swap(s[i], s[i + 1]);
                i++;
            }
    }

    std::cout << s << '\n';

    return 0;
}