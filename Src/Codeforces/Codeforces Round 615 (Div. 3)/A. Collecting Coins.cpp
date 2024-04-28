#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N];
int T, m;

void solve()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int maxn, ans;
    maxn = max(a, max(b, c));

    ans = maxn - a + maxn - b + maxn - c;

    if (((a + b + c + n) % 3 == 0) && (ans <= n) && ((n - ans) % 3 == 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
