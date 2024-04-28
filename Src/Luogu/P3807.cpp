#include <bits/stdc++.h>
#define int long long
using namespace std;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int c(int a, int b, int p)
{
    if (b > a)
        return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = res * j % p;
        res = res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas(int a, int b, int p)
{
    if (a < p && b < p)
        return c(a, b, p);
    return c(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, p;
        cin >> a >> b >> p;
        cout << lucas(a + b, b, p) << endl;
    }
    return 0;
}