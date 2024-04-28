#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N];
int T, n, m;

bool cmp(const int &a, const int &b)
{
    return a > b;
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3, cmp);
    if (a[0])
    {
        a[0]--;
        ans++;
    }
    if (a[1])
    {
        a[1]--;
        ans++;
    }
    if (a[2])
    {
        a[2]--;
        ans++;
    }
    if (a[0] && a[1])
    {
        a[0]--, a[1]--;
        ans++;
    }
    if (a[0] && a[2])
    {
        a[0]--, a[2]--;
        ans++;
    }
    if (a[1] && a[2])
    {
        a[1]--, a[2]--;
        ans++;
    }
    if (a[0] && a[1] && a[2])
    {
        a[0]--, a[1]--, a[2]--;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
