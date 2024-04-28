#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
const int mod = 1e5 + 3;
int f[N];

signed main()
{
    f[1] = 1;
    f[2] = 2;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        f[i] = (f[i - 1] % mod + f[i - 2] % mod) % mod;
    cout << f[n] % mod << endl;
    return 0;
}