#include <bits/stdc++.h>
using namespace std;
int n, m, k, a;
int day[1010][1010];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a), day[a][j] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= m; j++)
            day[i][j] += day[i][j - 1];
        printf("%d ", day[i][m]);
    }
    return 0;
}