#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int s[N];

signed main()
{
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        s[i] += s[i - 1] + x;
    }
    // 前缀和维护

    if (s[n] % 3)
        puts("0");
    // 如果有组合，数组之和必须是3的倍数
    else
    {
        int res = 0, cnt = 0;
        for (int i = 2; i < n; i++)
        {
            //注意此处i不可以取到n（i代表的是第二个分割点，如果取到n的话就不存在第三段了）
            if (s[i - 1] == s[n] / 3)
                cnt++;
            // cnt用于统计i之前有多少个位置的前缀和等于s/3
            if (s[i] == s[n] / 3 * 2)
                res += cnt;
            // 如果s[i]能做第二个分割点，那么答案就是res加上以i为第二分割点，i-1中能做第一分割点的个数
        }
        cout << res << endl;
    }
    return 0;
}