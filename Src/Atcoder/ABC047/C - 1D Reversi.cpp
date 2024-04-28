#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;

signed main()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1])
            res++;
    cout << res << endl;

    return 0;
}