#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

int main()
{
    string s, S, T;
    cin >> s;
    int res = 0;
    int n = s.size();
    for (int i = 0; i <= (n >> 1) - 1; i++)
        res += (s[i] != s[0]);
    if (!res)
    {
        puts("Impossible");
        return 0;
    }
    for (int i = 1; i <= (n >> 1); i++)
    {
        T = s.substr(i, n) + s.substr(0, i);
        S = T;
        reverse(S.begin(), S.end());
        if (S == T && S != s)
        {
            puts("1");
            return 0;
        }
    }
    puts("2");
    return 0;
}
