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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r)
        {
            // 左端点：第一个大于等于x
            int mid = l + r >> 1;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }

        if (a[r] != x)
            puts("-1 -1");
        else
        {
            cout << r << ' ';
            // 右端点：最后一个大于等于x
            l = l, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a[mid] > x)
                    r = mid - 1;
                else
                    l = mid;
            }
            cout << l << endl;
        }
    }
    return 0;
}