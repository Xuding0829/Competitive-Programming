#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> n >> s;
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';

        string t;
        t += s[0];
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1])
                t += s[i];

        if (t == "meow")
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}