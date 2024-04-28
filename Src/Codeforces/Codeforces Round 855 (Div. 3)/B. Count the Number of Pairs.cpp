#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;
int lo[26], up[26];

void solve()
{
    memset(lo, 0, sizeof (lo));
    memset(up, 0, sizeof(up));
    string s;
    cin >> n >> m >> s;
    for (auto i : s)
        if (i >= 'A' && i <= 'Z')
            up[i - 'A']++;
        else
            lo[i - 'a']++;

    int maxn = 0;
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        res += min(up[i], lo[i]);
        maxn += (up[i] + lo[i]) / 2;
    }
    res = min(res + m, maxn);
    cout << res << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}