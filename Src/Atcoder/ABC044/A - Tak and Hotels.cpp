#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int res;

signed main()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    if (k > n)
        cout << x * n << endl;
    else
    {
        res += x * k;
        res += (n - k) * y;
        cout << res << endl;
    }

    return 0;
}