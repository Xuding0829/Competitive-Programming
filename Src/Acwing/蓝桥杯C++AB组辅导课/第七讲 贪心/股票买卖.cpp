#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] > a[i - 1])
            res += a[i] - a[i - 1];
    }
    cout << res << endl;
    return 0;
}