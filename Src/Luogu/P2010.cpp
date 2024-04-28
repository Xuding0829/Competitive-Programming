#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, a, b, c, ans;
    int s[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::cin >> n >> m;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= s[i]; j++)
        {
            c = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            int sum = c * 10000 + i * 100 + j;
            if (sum < n || sum > m)
                continue;
            ans++;
        }
    std::cout << ans << '\n';

    return 0;
}