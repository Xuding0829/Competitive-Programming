#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

bool check(int mid, int x)
{
    if (a[mid] > x)
        return false;
    else
        return true;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    while (m--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid, x))
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] <= x)
            cout << a[l] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}