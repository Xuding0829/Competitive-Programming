#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

signed main()
{
    cin >> n >> m;
    n %= m;
    n = min(n, abs(n - m));
    cout << n << endl;
    return 0;
}