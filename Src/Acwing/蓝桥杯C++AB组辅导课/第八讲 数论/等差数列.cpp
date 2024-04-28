#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int d = 0;
    for (int i = 1; i < n; i++)
        d = __gcd(d, a[i] - a[i - 1]);
    if (!d)
        cout << n << endl;
    else
        cout << (a[n - 1] - a[0]) / d + 1 << endl;
    return 0;
}