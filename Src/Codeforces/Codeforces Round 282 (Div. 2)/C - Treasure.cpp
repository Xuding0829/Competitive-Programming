#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int a = 0, k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            a++;
        else if (s[i] == ')')
            a--;
        else
            a--, k++;
        if (a < 0)
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    int p = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            p++;
        else if (s[i] == ')')
            p--;
        else
        {
            c++;
            if (c == k)
                p -= a;
            p--;
        }
        if (p < 0)
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < k - 1; i++)
        std::cout << "1\n";
    std::cout << a + 1 << '\n';

    return 0;
}