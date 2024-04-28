#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int h[N], cnt;
int T, n, m;
bool flag;
string s;

void down(int x)
{
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t])
        t = 2 * x + 1;
    if (t != x)
    {
        swap(h[t], h[x]);
        down(t);
    }
        
}

signed main()
{
    ios;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    cnt = n;

    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        cout << h[1] << ' ';
        h[1] = h[cnt--];
        down(1);
    }

    return 0;
}
