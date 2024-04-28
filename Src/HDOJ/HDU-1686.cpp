#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using i64 = long long;

const int N = 1e6 + 100;

void solve()
{

    std::string s, p;
    std::cin >> p >> s;

    int n = s.size(), m = p.size();
    std::vector<int> ne(m + 1);
    for (int i = 2, j = 0; i < m + 1; i++)
    {
        while (j && p[i - 1] != p[j])
            j = ne[j];
        if (p[i - 1] == p[j])
            j++;
        ne[i] = j;
    }

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != p[j])
            j = ne[j];
        if (s[i] == p[j])
            j++;
        if (j == p.size())
        {
            res++;
            j = ne[j];
        }
    }
    std::cout << res << '\n';
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