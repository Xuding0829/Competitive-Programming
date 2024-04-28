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

int n, m, k, q;
int a[N];

int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

void solve()
{
    cin >> n >> k;                         // 组合数学， 第一个球有k种选择， 第2....n个各有 k - 1 种选择 res = k * (k - 1) ^ (n - 1)
    cout << k * qmi(k - 1, n - 1) << endl; // 快速幂求次方
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
