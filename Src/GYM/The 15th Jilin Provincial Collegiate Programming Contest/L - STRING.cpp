#include <bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 2e5 + 100;

int n, ans;

void solve()
{
    string s;
    cin >> s;
    int t = s.size();
    ans = t - 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[0])
        {
            ans = 2 * t - i;
            break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
