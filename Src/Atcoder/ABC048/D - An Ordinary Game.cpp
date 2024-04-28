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

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    if (s[0] == s[len - 1] && (len - 2) & 1)
        puts("Second");
    else if (s[0] == s[len - 1] && !((len - 2) & 1))
        puts("First");
    else if (s[0] != s[len - 1] && (len - 2) & 1)
        puts("First");
    else
        puts("Second");
    //  puts((n + (s[0] == s[n-1])) % 2 ? "First" : "Second"); 网上看到的精简代码
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
