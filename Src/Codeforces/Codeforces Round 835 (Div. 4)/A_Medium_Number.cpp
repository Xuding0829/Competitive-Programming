#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    cout << a[1] << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}