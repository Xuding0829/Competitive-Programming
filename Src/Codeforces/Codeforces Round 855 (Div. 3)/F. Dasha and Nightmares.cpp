#include <bits/stdc++.h>

using i64 = long long;

int f[1 << 26];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::vector<std::array<int, 26>> cnt(n);
    std::vector<int> mask(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
        for (auto it : s[i])
            cnt[i][it - 'a']++; // 统计s[i]中各个字母出现的次数
        for (int j = 0; j < 26; j++)
            mask[i] |= (cnt[i][j] % 2) << j; // 讲s[i]的各个字母的出现情况转化为01串
    }

    i64 res = 0;
    for (int i = 0; i < 26; i++)
    {
        int tmp = (1 << 26) - 1 - (1 << i); // 枚举缺少每一位的情况
        for (int j = 0; j < n; j++)
        {
            if (cnt[j][i] == 0)
            {
                f[mask[j]]++;
                res += f[mask[j] ^ tmp];
            }
        }

        for (int j = 0; j < n; j++)
            if (cnt[j][i] == 0)
                f[mask[j]]--;
    }
    std::cout << res << '\n';

    return 0;
}