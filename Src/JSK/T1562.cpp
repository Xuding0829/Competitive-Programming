#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

bool check(int mid, int x)
{
    if (a[mid] > x)
        return true;
    else
        return false;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    while (m--)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid, x))
                r = mid;
            else
                l = mid + 1;
        }

        if (a[l] > x)
            cout << a[l] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}