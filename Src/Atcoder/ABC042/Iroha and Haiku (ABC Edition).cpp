#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
int a[N];

signed main()
{
    for (int i = 0, x; i < 3; i++)
    {
        cin >> x;
        a[x]++;
    }

    if (a[5] == 2 && a[7] == 1)
        puts("YES");
    else
        puts("NO");

    return 0;
}