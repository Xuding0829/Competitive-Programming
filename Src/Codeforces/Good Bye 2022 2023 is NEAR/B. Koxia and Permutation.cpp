#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N];
int T, n, m, k;
bool flag;
string s;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            cout << n - i / 2 << " ";
        else
            cout << i / 2 << " ";
    }
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
