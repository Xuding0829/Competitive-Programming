#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define int long long
#define lowbit(x) (x & -x)
#define mst(a, b) memset(a, b, sizeof(a))
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;

const double eps = 1e-6;
const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 1e6 + 100;
const int inf = 0x3f3f3f;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int a[N];

void solve()
{
    int n, m, k, q;
    cin >> n >> k;
    memset(a, 0, sizeof a);

    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        for (int j = 30; j >= 0; j--)
            if (x >> j & 1)
                ;
            else
                a[j]++;
    }

    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        if (k >= a[i])
        {
            k -= a[i];
            ans += 1 << i;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int T;
    T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
