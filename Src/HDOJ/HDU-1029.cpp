#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];
int ans;

signed main()
{
    // 直接用cin会tle，需开ios
    while (scanf("%d", &n) != EOF)
    {
        map<int, int> mp;
        mp.clear();
        m = (n + 1) / 2;
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            mp[x]++;
        }
        //用map存储对应关系，另有省时间空间的做法参考-2
        for (auto i : mp)
            if (i.second >= m)
            {
                ans = i.first;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}