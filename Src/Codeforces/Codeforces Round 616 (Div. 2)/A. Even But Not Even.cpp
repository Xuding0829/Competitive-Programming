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
string s;

void solve()
{
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 2)
            break;
        if (s[i] % 2 == 1)
            a[cnt++] = s[i] - '0';
    }
    if (cnt == 2)
        cout << a[0] << a[1] << endl;
    else
        cout << -1 << endl;
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
