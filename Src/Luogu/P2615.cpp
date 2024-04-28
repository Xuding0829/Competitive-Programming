#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 40;
int a[maxn][maxn];
int x, y;
int n;
int main()
{
    cin >> n;
    a[1][n / 2 + 1] = 1;
    x = 1, y = n / 2 + 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (x == 1 && y != n)
        {
            a[n][y + 1] = i;
            x = n;
            y++;
        }
        else if (y == n && x != 1)
        {
            a[x - 1][1] = i;
            x--;
            y = 1;
        }
        else if (x == 1 && y == n)
        {
            a[x + 1][y] = i;
            x++;
        }
        else if (x != 1 && y != n)
        {
            if (a[x - 1][y + 1] == 0)
            {
                a[x - 1][y + 1] = i;
                x--;
                y++;
            }
            else
            {
                a[++x][y] = i;
            }
            continue;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}