#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6;

void solve()
{
    ll n, g = 0, maxn = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    maxn = a[n - 1] / g;
    cout << maxn << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
