#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int dp[N];
int mod = 100003;
int res;

signed main()
{
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(m, i); j++)
            dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
    cout << dp[n] << endl;
    return 0;
}