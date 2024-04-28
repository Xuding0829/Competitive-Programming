#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110;
char g[N][N];
int n, m;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    for (int i = 1; i <= 2 * n; i++)
        cout << g[(i + 1) / 2] << endl;
    return 0;
}