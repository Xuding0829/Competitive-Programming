#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;

signed main()
{
    cin >> n;
    int res = n;
    while (n >= 3)
    {
        res += n / 3;
        n = n / 3 + n % 3;
        // n代表瓶盖数量
    }
    cout << res << endl;
    return 0;
}