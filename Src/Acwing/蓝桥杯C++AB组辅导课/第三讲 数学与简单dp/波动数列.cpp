#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 1010;
const int mod = 1e8 + 7;
int n, s, a, b;
int f[N][N];

int get_mod(int a, int b)
{
    return (a % b + b) % b;
    // 求正余数
}

signed main()
{
    cin >> n >> s >> a >> b;

    f[0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++)
        {
            f[i][j] = (f[i - 1][get_mod(j - (n - i) * a, n)] + f[i - 1][get_mod(j + (n - i) * b, n)]) % mod;
            // 注意这边要求正余数
            // cout << "i " << i << " j " << j << ' ' << f[i][j] << endl;
        }

    cout << f[n - 1][get_mod(s, n)] << endl; // 注意这边要求正余数

    return 0;
}