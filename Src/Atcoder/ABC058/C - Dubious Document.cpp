#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::vector<std::string> a(n);
    std::vector<std::array<int, 26>> cnt(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < a[i].size(); j++)
            cnt[i][a[i][j] - 'a']++;

    std::vector<int> num(26, inf);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            num[j] = std::min(cnt[i][j], num[j]);

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < num[i]; j++)
            s += 'a' + i;

    std::cout << s << '\n';
    return 0;
}