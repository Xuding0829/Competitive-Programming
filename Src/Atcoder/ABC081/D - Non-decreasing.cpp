#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int main()
{
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (abs(a[i]) >= abs(a[p]))
            p = i;
    }

    cout << 2 * n - 1 << endl;

    for (int i = 1; i <= n; i++)
        cout << p << ' ' << i << endl;

    if (a[p] > 0)
        for (int i = 1; i < n; i++)
            cout << i << ' ' << i + 1 << endl;
    else
        for (int i = n; i > 1; i--)
            cout << i << ' ' << i - 1 << endl;
    return 0;
}