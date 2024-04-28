#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
int a[N];
int n, m;
int depth = 1, maxv = -0x3f3f3f;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1, d = 1; i <= n; i *= 2, d++)
    {
        int s = 0;

        for (int j = i; j < i + (1 << d - 1) && j <= n; j++)
            s += a[j];

        // cout << "i == " << i << " d == " << d << " w = " << s << endl;

        if (s > maxv)
        {
            depth = d;
            maxv = s;
        }
    }

    cout << depth << endl;
    return 0;
}