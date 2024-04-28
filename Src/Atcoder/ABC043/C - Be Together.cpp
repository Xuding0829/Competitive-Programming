#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

signed main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    sum = sum /  n;

    int res = 0, res2 = 0, res3 = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] - sum) * (a[i] - sum);
        res2 += (a[i] - (sum + 1)) * (a[i] - (sum + 1));
        res3 += (a[i] - (sum - 1)) * (a[i] - (sum - 1));
    }
    res = min(res, res2);
    res = min(res, res3);
    cout << res << endl;
    return 0;
}