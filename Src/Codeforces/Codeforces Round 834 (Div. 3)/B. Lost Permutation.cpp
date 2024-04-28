#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e6;

int a[100], b[N];

void solve()
{
    map<int, int> cnt;
    int n, s;
    int maxn = 0, maxk = 0;
    int sum = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;                 // cnt is the times;
        sum += a[i];                 // sum is sum of a[i];
        maxn = max(maxn, cnt[a[i]]); // maxn is the times of a[i] appearing;
        maxk = max(maxk, a[i]);      // maxn is the bigest a[i];
    }

    if (maxn > 1)
    {
        cout << "NO" << endl;
        return;
    }

    int k = 0;
    for (int i = 1; i < N; i++)
    {
        if ((1 + i) * i / 2 == sum + s)
        {
            k = i;
            break;
        }
    }
    if (k < maxk)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
    }

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
