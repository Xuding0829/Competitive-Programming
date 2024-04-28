#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    string s;
    cin >> n >> s;
    int ans = 'a';
   
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= ans)
            ans = s[i];
    }
    cout << ans - 97 + 1 << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}