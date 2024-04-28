#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    int x, res = 0;
    cin >> n >> m >> x;
    if (n == 0)
        res = m / x - n / x + 1;
    else
        res = m / x - (n - 1) / x;
    cout << res << endl;
    return 0;
}