#include <bits/stdc++.h>
// #define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 2e5 + 100;

int n, m, k, q;
int a[N];

void solve()
{
    cin >> n;
    int maxn = -N, minn = N;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x >= maxn)
            maxn = x;
        if (x <= minn)
            minn = x;
    }
    cout << (maxn - minn) * n << endl;
}

signed main()
{
    // ios;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
