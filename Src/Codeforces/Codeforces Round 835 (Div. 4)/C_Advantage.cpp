#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N], b[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int maxn1 = b[n];
    int maxn2 = b[n - 1];
    for (int i = 1; i <= n; i++)
    {
        if(a[i] == maxn1)
            cout << a[i] - maxn2 << ' ';
        else
            cout << a[i] - maxn1 << ' ';
    }
    cout << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}