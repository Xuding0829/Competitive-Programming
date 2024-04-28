#include <bits/stdc++.h>
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

int n, m;
int a[N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int g[200][200];

void solve()
{
    cin >> n;
    int ans = 0;
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= n; i++)
    {
        char x, y;
        cin >> x >> y;
        g[x][y]++;
        for (int j = 'a'; j <= 'k'; j++)
        {
            if (y != j)
                ans += g[x][j];
            if (x != j)
                ans += g[j][y];
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
