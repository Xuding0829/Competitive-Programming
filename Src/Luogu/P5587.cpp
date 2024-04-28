#include <bits/stdc++.h>

using i64 = long long;

const int N = 10010;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1[N], s2[N];

    int n = 0, m = 0;

    while (1)
    {
        getline(std::cin, s1[++n]);

        for (int i = 0; i < s1[n].size(); i++)
        {
            if (s1[n][i] == '<')
            {
                if (i - 1 >= 0)
                    s1[n].erase(i, 1), s1[n].erase(i - 1, 1), i -= 2;
                else
                    s1[n].erase(i, 1), i--;
            }
        }
        if (s1[n] == "EOF")
            break;
    }

    while (1)
    {
        getline(std::cin, s2[++m]);
        for (int i = 0; i < s2[m].size(); i++)
        {
            if (s2[m][i] == '<')
            {
                if (i - 1 >= 0)
                    s2[m].erase(i, 1), s2[m].erase(i - 1, 1), i -= 2;

                else
                    s2[m].erase(i, 1), i--;
            }
        }
        if (s2[m] == "EOF")
            break;
    }

    int t;
    std::cin >> t;

    int res = 0;
    for (int i = 1; i < std::min(n, m); i++)
    {
        int len = std::min(s1[i].size(), s2[i].size());
        for (int j = 0; j < len; j++)
            if (s1[i][j] == s2[i][j])
                res++;
    }

    int kpm = (res * 1.0 / t * 60.0 + 0.5);
    std::cout << kpm << '\n';
    return 0;
}