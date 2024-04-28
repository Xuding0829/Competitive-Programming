#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n, c, d;
int a[N];
int s[N];

bool cmp(int x, int y)
{
    return x > y;
}

bool check(int k)
{
    int res1 = s[min(n, 1 + k)] * (d / (1 + k));
    int res2 = s[min(n, d % (1 + k))];
    if ((res1 + res2) >= c)
        return true;
    else
        return false;
}

void solve()
{
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    if (a[1] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    else if (s[min(n, d)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    else
    {
        int l = 0, r = d;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        if (l < d)
            cout << l << endl;
    }
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}