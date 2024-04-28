#include <bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 2e5 + 100;

int n, m;
int a[N];

void solve()
{
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x & 1)
            even++;
        else
            odd++;
    }
    if (abs(even - odd) <= 1)
        cout << "Good" << endl;
    else
        cout << "Not Good" << endl;
}

signed main()
{
    ios;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
