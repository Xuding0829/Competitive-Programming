#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

int qmul(int a, int b, int p)
{
    int res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return res % p;
}

signed main()
{
    int a, b, p; 
    cin >> a >> b >> p;
    cout << qmul(a, b, p) << endl;
    return 0;
}