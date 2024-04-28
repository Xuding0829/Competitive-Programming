#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    string s;
    string res;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z' && (s[i - 1] == ' ' || !i))
            res += s[i];
    cout << res << endl;
    return 0;
}