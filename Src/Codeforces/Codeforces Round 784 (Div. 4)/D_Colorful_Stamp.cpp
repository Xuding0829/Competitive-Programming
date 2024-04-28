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
    string s;
    cin >> n >> s;
    int cnt_B = 0, cnt_R = 0;
    bool flag = true;
    s += 'W';
    for (int i = 0; i < n + 1; i++)
    {
        if (s[i] == 'W')
        {
            if (cnt_B == 0 && cnt_R > 0 || cnt_R == 0 && cnt_B > 0)
            {
                flag = false;
                break;
            }
            cnt_B = 0, cnt_R = 0;
        }
        else if (s[i] == 'B')
            cnt_B++;
        else if (s[i] == 'R')
            cnt_R++;
    }
    puts(flag ? "YES" : "NO");
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
