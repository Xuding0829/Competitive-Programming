#include <bits/stdc++.h>

using i64 = long long;

int k;
std::string s;

int dfs()
{
    int res = 0;
    while (k < s.size())
    {
        if (s[k] == '(')
        {
            k++;
            res += dfs();
            k++;
        }
        else if (s[k] == ')')
            break;
        else if (s[k] == '|')
            k++, res = std::max(res, dfs());
        else
            res++, k++;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s;
    std::cout << dfs() << '\n';

    return 0;
}