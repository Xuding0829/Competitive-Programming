//TLE 6
#include <bits/stdc++.h>
using namespace std;

const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 2e5 + 100;

int n, ans;
map<int, int> mp;

void solve()
{
    mp.clear();

    int a, b, m, x0, x;
    cin >> a >> b >> m >> x0 >> x;
    a = a % m;
    b = b % m;
    x = x % m;
    x0 = x0 % m;
    if (x0 == x)
    {
        puts("YES");
        return;
    }

    if (a == 0)
    {
        if (b == x)
            puts("YES");
        else
            puts("NO");
        return;
    }

    while (!mp.count(x0))
    {
        mp[x0] = 1;
        x0 = (a * x0 + b) % m;
        if (mp.count(x))
        {
            puts("YES");
            return;
        }
    }

    puts(mp.count(x) ? "YES" : "NO");
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
