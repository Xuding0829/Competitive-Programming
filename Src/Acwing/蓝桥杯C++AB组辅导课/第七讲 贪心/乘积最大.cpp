#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
const int mod = 1000000009;
int a[N];
int n, m;
int res = 1;

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int sign = 1;
    int i = 0, j = n - 1;
    if (m % 2)
    {
        res = a[j--];
        m--;
        if (res < 0)
            sign = -1;
    }
    while (m)
    {
        int x = a[i] * a[i + 1];
        int y = a[j] * a[j - 1];
        if (x * sign > y * sign)
        {
            res = ((res % mod) * (x % mod)) % mod;
            i += 2;
        }
        else
        {
            res = ((res % mod) * (y % mod)) % mod;
            j -= 2;
        }
        m -= 2;
    }
    cout << res << endl;
    return 0;
}