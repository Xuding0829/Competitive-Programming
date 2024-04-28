#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55;
int n, m;

void solve()
{

    char a[N][N];
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int j = 1; j <= m; j++)
    {
        int lowest = n;
        for (int i = n; i >= 1; i--)
        {
            if (a[i][j] == 'o')
                lowest = i - 1;
            if (a[i][j] == '*')
            {
                swap(a[i][j], a[lowest][j]);
                lowest--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << endl;
    }
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}