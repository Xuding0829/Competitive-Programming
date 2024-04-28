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
const double eps = 1e-6;
int n, m, k, q, t;
int a[N];
int res;
bool st[N];

struct Edge
{
    double l, r;
    bool operator<(const Edge &t) const
    {
        return r < t.r;
    }
} seg[N];

void solve()
{
    int n, d;
    cin >> n >> d;

    bool failed = false;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        y = abs(y);
        if (y > d)
        {
            failed = true;
            break;
        }
        double len = sqrt(d * d - y * y);
        seg[i] = {x - len, x + len};
    }

    if (failed)
        puts("-1");
    else
    {
        sort(seg, seg + n);
        for (int i = 0; i < n; i++)
            if (!st[i])
            {
                res++;
                for (int j = i + 1; j < n; j++)
                    if (seg[j].l <= seg[i].r)
                        st[j] = true;
            }
        cout << res << endl;
        // sort(seg, seg + n);
        // double last = -INF;
        // for (int i = 0; i < n; i++)
        //     if (seg[i].l > last + eps)
        //         res++, last = seg[i].r;
        // cout << res << endl;
    }
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
