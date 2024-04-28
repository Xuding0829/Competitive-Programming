#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N];

signed main()
{
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        a[i] += 1;
        for (int j = 1; j <= i / 2; j++)
            a[i] += a[j];
    }
    cout << a[n] << endl;
    return 0;
}