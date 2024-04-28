#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 100;

int n, m, k;
int s[N];
int cnt[N];
// cnt[i] 存储 s[] % k 余数为 i的个数

int res;

signed main()
{
    cin >> n >> k;

    // 对于一段区间 (s[r] - s[l - 1]) % k == 0 --> s[r] % k == s[l - 1] % k;因此问题转化为了求同余区间内的个数

    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        s[i] += s[i - 1] + x;
    }
    // 前缀和维护

    cnt[0] = 1;
    // cnt[0] = 1 第一次出现s[i] % k == 0 时，即1~i这个区间是k倍区间，此时res 应该+1，但由于cnt[0] = 0, res 并没有 +1 ，所以cnt[0]应该初始化为1
    for (int i = 1; i <= n; i++) // 要求有序，从前往后遍历
    {
        res += cnt[s[i] % k];
        // 对于s[i], res 加上与 s[i] 同余区间的个数
        cnt[s[i] % k]++;
        // 对应的s[i] % k 的个数++
        // 由于不存在s[i] ~ s[i]这样的区间，统计区间数量应在后面
    }
    cout << res << endl;
    return 0;
}

//  暴力写法
//  for (int i = 1; i <= n; i++)
//      for (int j = i; j <= n; j++)
//          if ((s[j] - s[i - 1]) % k == 0)
//              res++;
