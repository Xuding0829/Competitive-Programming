#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
using namespace std;
typedef long long ll;
// **************************************************************************************************
const int N = 1e5 + 100;
int n, m;
int a[N], b[N], c[N];
int cnt[N], s[N]; // cnt 用于统计a[i]出现的次数
int cntA[N], cntC[N];
// **************************************************************************************************
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]++;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]++;
    for (int i = 0; i < n; i++)
        cin >> c[i], c[i]++;
    // **************************************************************************************************
    for (int i = 0; i < n; i++)
        cnt[a[i]]++; // 统计a[i]出现的次数
    for (int i = 1; i < N; i++)
        s[i] = s[i - 1] + cnt[i]; // s[i] 表示数组 a 中小于等于 i 的数的个数
    for (int i = 0; i < n; i++)
    {
        cntA[i] = s[b[i] - 1];
        // cntA[i] 表示 数组a中小于b[i]的个数
    }
    // **************************************************************************************************
    memset(cnt, 0, sizeof(cnt));
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++)
        cnt[c[i]]++; // 统计c[i]出现的次数
    for (int i = 1; i < N; i++)
        s[i] = s[i - 1] + cnt[i]; // s[i] 表示数组 c 中小于等于 i 的数的个数
    for (int i = 0; i < n; i++)
    {
        // ************************
        cntC[i] = s[N - 1] - s[b[i]]; // 注意
        // ************************
        // cntC 表示 数组c中大于b[i]的个数
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += (ll)cntA[i] * (ll)cntC[i];
    cout << res << endl;
    return 0;
}