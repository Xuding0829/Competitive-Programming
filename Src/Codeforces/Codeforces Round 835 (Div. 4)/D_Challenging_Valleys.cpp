#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int n;
int a[N];

void solve()
{
    cin >> n;
    int cnt;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> res;
    res.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            res.push_back(a[i]);

    int ans = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if ((i == 0 || res[i - 1] > res[i]) && (i == res.size() - 1 || res[i] < res[i + 1]))
            ans++;
    }
    puts(ans == 1 ? "YES" : "NO");
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}