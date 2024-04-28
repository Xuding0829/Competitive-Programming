#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        if (2 * l > r)
            cout << 0 << endl;
        else if (2 * l == r)
            cout << 1 << endl;
        else
        {
            int t = r - 2 * l + 1;
            cout << (1 + t) * t / 2 << endl;
        }
    }
    return 0;
}