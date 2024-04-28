#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;

signed main()
{
    cin >> n >> m;
    int k = n + m + 1;

    for (int i = 0; i < n + m + 1; i++)
        cin >> a[i];

    if (!m)
        for (int i = 0; i < k; i++)
            res += a[i];
    else
    {
        sort(a, a + n + m + 1);
        res = a[k - 1] - a[0];
        for (int i = 1; i < k - 1; i++)
            res += abs(a[i]);
    }
    cout << res << endl;
    return 0;
}