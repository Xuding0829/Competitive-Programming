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
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            int t = x % 10;
            x /= 10;
            if (t == 1 || t == 0 || t == 2 || t == 9)
            {
                res += i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}