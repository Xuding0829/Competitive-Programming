#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (auto it : s)
        cnt[it - 'A']++;

    int odd = -1;
    for (int i = 0; i < 26; i++)
        if (cnt[i] & 1)
        {
            if (odd == -1)
                odd = i;
            else if (odd != -1)
            {
                std::cout << "NO SOLUTION\n";
                return 0;
            }
        }

    std::string res;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < cnt[i] / 2; j++)
            res += 'A' + i;

    if (odd != -1)
    {
        std::cout << res << (char)('A' + odd);
        std::reverse(res.begin(), res.end());
        std::cout << res;
    }
    else
    {
        std::cout << res;
        std::reverse(res.begin(), res.end());
        std::cout << res;
    }
    return 0;
}