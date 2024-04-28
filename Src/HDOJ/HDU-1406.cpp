#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];
int cnt;

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        if (n > m)
            swap(n, m);
        cnt = 0;
        for (int i = n; i <= m; i++)
        {
            int sum = 1;
            for (int j = 2; j <= i / j; j++)
            {
                if ((i % j) == 0)
                    sum += j + i / j;
            }
            if (sum == i)
                cnt++;
        }
        cout << cnt << endl;
    }
}