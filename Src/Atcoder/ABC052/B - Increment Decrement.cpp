#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int res = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            tmp++, res = std::max(res, tmp);
        else
            tmp--, res = std::max(res, tmp);
    }

    std::cout << res << '\n';

    return 0;
}