#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 100;
int a[N], c[N];
int n, m;
int res, sum, average;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    average = sum / n;
    for (int i = 2; i <= n; i++)
        c[i] = c[i - 1] - average + a[i];
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        res += abs(c[i] - c[(n + 1) / 2]);
    cout << res << endl;
    return 0;
}