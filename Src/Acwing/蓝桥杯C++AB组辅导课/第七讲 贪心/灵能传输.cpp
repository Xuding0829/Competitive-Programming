#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 3e5 + 100;
const int mod197 = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m, k, q, t;
int a[N], s[N];
bool st[N];
int res;

// 前缀和处理后 ： max(s[i] - s[i - 1]

void solve()
{
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    memset(st, 0, sizeof(st));

    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] += s[i - 1];

    int s0 = s[0], sn = s[n];
    if (s0 > sn)
        swap(s0, sn);

    sort(s, s + n + 1);

    for (int i = 0; i <= n; i++)
        if (s[i] == s0)
        {
            s0 = i;
            break;
        }

    for (int i = n; i >= 0; i--)
        if (s[i] == sn)
        {
            sn = i;
            break;
        }

    int l = 0, r = n;
    for (int i = s0; i >= 0; i -= 2)
    {
        a[l++] = s[i];
        st[i] = 1;
    }

    for (int i = sn; i <= n; i += 2)
    {
        a[r--] = s[i];
        st[i] = 1;
    }

    for (int i = 0; i <= n; i++)
        if (!st[i])
            a[l++] = s[i];

    res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, abs(a[i] - a[i - 1]));

    cout << res << endl;
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
