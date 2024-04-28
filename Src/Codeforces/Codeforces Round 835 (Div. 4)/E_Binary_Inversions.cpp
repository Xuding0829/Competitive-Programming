#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int n;
int a[N];
int find(int a[])
{
    int ans = 0;
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i])
            cnt1++;
        else
            ans += cnt1;
    }
    return ans;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    sum1 = find(a);
    for (int i = 1; i <= n; i++)
    {
        if(!a[i])
        {
            a[i] = 1;
            sum2 = find(a);
            a[i] = 0;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if(a[i])
        {
            a[i] = 0;
            sum3 = find(a);
            a[i] = 1;
            break;
        }
    }
    cout << max(sum1, max(sum2, sum3)) << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}