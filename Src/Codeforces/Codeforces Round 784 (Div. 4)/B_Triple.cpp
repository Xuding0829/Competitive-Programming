#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define int long long
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
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

void solve()
{
    cin >> n;
    int ans = -1;
    // 这个写法有问题
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] >= 3)
        {
            ans = x;
        }
    }
    cout << ans << endl;
    // memset(a, 0, sizeof(a));
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     a[x]++;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] >= 3)
    //     {
    //         cout << i << endl;
    //         return;
    //     }
    // }
    // cout << "-1" << endl;
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
