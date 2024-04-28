#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100, M = 3100010;

int a[N], son[M][2], idx;
int T, n, m;
bool flag;
string s;

void insert(int x)
{
    int p = 0;
    for (int i = 30; ~i; i--)
    {
        int s = x >> i & 1;
        if (!son[p][s])
            son[p][s] = ++idx;
        p = son[p][s];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; ~i; i--)
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}

signed main()
{
    ios;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, query(a[i]));

    cout << res << endl;
    return 0;
}
