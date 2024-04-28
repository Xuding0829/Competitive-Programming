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

void solve()
{
    vector<PII> a(3);
    int b[3] = {0};
    for (int i = 0; i < 3; i++)
        cin >> a[i].first >> a[i].second;
        
    b[0] = abs(a[1].first - a[0].first) * abs(a[1].first - a[0].first) + abs(a[1].second - a[0].second) * abs(a[1].second - a[0].second);
    b[1] = abs(a[2].first - a[1].first) * abs(a[2].first - a[1].first) + abs(a[2].second - a[1].second) * abs(a[2].second - a[1].second);
    b[2] = abs(a[2].first - a[0].first) * abs(a[2].first - a[0].first) + abs(a[2].second - a[0].second) * abs(a[2].second - a[0].second);

    if ((b[1] + b[0] == b[2] || b[1] + b[2] == b[0] || b[2] + b[0] == b[1]) && (a[1].first - a[0].first == 0 || a[2].first - a[1].first == 0 || a[2].first - a[0].first == 0) && (a[1].second - a[0].second == 0 || a[2].second - a[1].second == 0 || a[2].second - a[0].second == 0))
        cout << "NO" << endl;

    else
        cout << "YES" << endl;
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
