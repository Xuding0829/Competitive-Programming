#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 1e6 + 100;

int n, m;
int a[N];

signed main()
{
    while (scanf("%d", &n) != EOF)
    {
        //最容易想到的做法，但消耗时间空间——桶排序
        for (int i = 0; i < N; i++)
            a[i] = 0;

        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            a[x]++;
        }

        for (int i = 0; i < N; i++)
        {
            if (a[i] >= (n + 1) / 2)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}