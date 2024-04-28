#include <bits/stdc++.h>

using i64 = long long;

const int N = 1100;

std::string s[N];

bool cmp(std::string a, std::string b)
{
    return a + b > b + a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    std::sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        std::cout << s[i];
    std::cout << '\n';

    return 0;
}