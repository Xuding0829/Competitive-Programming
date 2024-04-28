#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;
int x[N], y[N];
bool st[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i] * 100 + y[i] <= m * 100)
            st[i] = true;
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            continue;
        flag = true;
        res = max(res, (100 - y[i]) % 100);
    }

    if (!flag)
        puts("-1");
    else
        cout << res << "\n";
        
    return 0;
}