#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
bool st[N];
int n, m;
int cnt;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            cnt++;
            for (int j = i; !st[j]; j = a[j]) // 判断是否成环， 记录环的数量
                st[j] = true;
        }
    }

    cout << n - cnt << endl;
    return 0;
}