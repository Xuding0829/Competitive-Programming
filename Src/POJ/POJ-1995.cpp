// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int mod;
        cin >> mod;
        cin >> n;
        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            res = (res % mod + qmi(a, b, mod) % mod) % mod;
        }

        cout << res << endl;
    }
    return 0;
}