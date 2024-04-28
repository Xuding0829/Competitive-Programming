#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int sum = s[0] - '0';
    for (int i = 1; i < n; i++)
        if (sum > 0)
        {
            std::cout << '-';
            sum -= s[i] - '0';
        }
        else
        {
            std::cout << '+';
            sum += s[i] - '0';
        }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}