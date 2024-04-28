#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m, w;
int a[N];

signed main()
{
    cin >> w >> m >> n;
    m--, n--;
    int x1 = m / w, x2 = n / w;
    int y1 = m % w, y2 = n % w;

    if (x1 % 2)
        y1 = w - y1 - 1;
    if (x2 % 2)
        y2 = w - y2 - 1;

    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;
}