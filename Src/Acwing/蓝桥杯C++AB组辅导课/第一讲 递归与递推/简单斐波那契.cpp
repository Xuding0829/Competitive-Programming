#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

signed main()
{
    cin >> n;
    int a = 0, b = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a << ' ';
        int c = a + b;
        a = b;
        b = c;
    }
    return 0;
}