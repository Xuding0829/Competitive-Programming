#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

void solve()
{
    char a[8][8];
    int col[8] = {0}, row[8] = {0};
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
                row[i]++;
            else if (a[i][j] == 'B')
                col[j]++;
        }

    for (int i = 0; i < 8; i++)
    {

        if (row[i] == 8)
        {
            cout << 'R' << '\n';
            return;
        }
        else if (col[i] == 8)
        {
            cout << 'B' << '\n';
            return;
        }
    }

    return;
}

int main()
{
    cin >> n;

    while (n--)
    {
        solve();
    }

    return 0;
}
