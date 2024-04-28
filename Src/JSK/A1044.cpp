#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

bool cmp(int a, int b)
{
    return a > b;
}

signed main()
{
    int n, m;
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (m)
            sort(a, a + n, cmp);
        else
            sort(a, a + n);
        cout << a[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << a[i];
        cout << endl;
    }

    return 0;
}