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
bool flag;

bool cmp(int x, int y)
{
    return x > y;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a + 1, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[0])
            a[0] = a[0] + a[i] + 1 >> 1;
    }
    cout << a[0] << endl;
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
