#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char g[N][N];
bool st[N][N];
int n, m;
int x, y;
int res;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        // cout << 'a' << ' ' << a << ' ' << " b " << b << endl;
        // cout << "st[a][b] == " << st[a][b] << endl;

        if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
            continue;

        if (g[a][b] != '.')
            continue;
        else
        {
            st[a][b] = true;
            res++;
            dfs(a, b);
        }
    }
}

signed main()
{
    while (cin >> m >> n && n && m)
    {
        memset(st, false, sizeof(st));
        res = 1;

        for (int i = 0; i < n; i++)
            cin >> g[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '@')
                {
                    x = i, y = j;
                    st[i][j] = true;
                }
            }

        // cout << " x " << x << " y " << y << endl;

        dfs(x, y);

        cout << res << endl;
    }
    return 0;
}