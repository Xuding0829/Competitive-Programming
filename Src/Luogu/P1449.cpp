#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1000;
int a[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int i = 0, t = 0;
    for (auto ch : s)
    {
        if (ch == '.')
            a[++i] = t, t = 0;
        else if (ch >= '0' && ch <= '9')
            t *= 10, t += ch - '0';
        else if (ch == '+')
            a[i - 1] = a[i - 1] + a[i], a[i] = 0, i--;
        else if (ch == '-')
            a[i - 1] = a[i - 1] - a[i], a[i] = 0, i--;
        else if (ch == '*')
            a[i - 1] = a[i - 1] * a[i], a[i] = 0, i--;
        else if (ch == '/')
            a[i - 1] = a[i - 1] / a[i], a[i] = 0, i--;
    }
    std::cout << a[1] << '\n';
    return 0;
}