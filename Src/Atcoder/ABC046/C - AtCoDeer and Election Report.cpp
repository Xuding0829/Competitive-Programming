#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 100;
const int mod197 = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m, k, q, t;
int a[N];
int res;

int my_ceil(int x, int y)
{
    return (x % y ? x / y + 1 : x / y);
} // cmath 中的 ceil 函数 存在精度丢失问题

void solve()
{
    cin >> t;
    int x, y;
    cin >> x >> y;
    t--;
    // cout << "x = " << x << " y= " << y << endl;
    while (t--)
    {
        int a, b, c = 0, d = 0;
        cin >> a >> b;
        if (a >= x && b >= y)
        {
            x = a, y = b;
            // cout << "x = " << x << " y= " << y << endl;
            continue;
        }
        if (a < x)
            c = my_ceil(x, a);
        if (b < y)
            d = my_ceil(y, b);
        int maxv = max(c, d);
        x = maxv * a, y = maxv * b;
        // cout << "x = " << x << " y= " << y << endl;
    }
    res = x + y;
    cout << res << endl;
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
