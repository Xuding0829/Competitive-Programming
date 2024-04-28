#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;

typedef pair<int, int> PII;
vector<PII> p;
const int N = 2e5 + 100;
const int mod = 998244353;
int n, m;
int f[N][2];

// 考虑 i - 1， i 这两张牌

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i].x != p[i - 1].x)
            (f[i][0] += f[i - 1][0]) %= mod;
        if (p[i].x != p[i - 1].y)
            (f[i][0] += f[i - 1][1]) %= mod;
        if (p[i].y != p[i - 1].x)
            (f[i][1] += f[i - 1][0]) %= mod;
        if (p[i].y != p[i - 1].y)
            (f[i][1] += f[i - 1][1]) %= mod;
    }

    int res = (f[n - 1][0] % mod + f[n - 1][1] % mod) % mod;
    cout << res << endl;
    return 0;
}