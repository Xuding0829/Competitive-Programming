#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int p[N], d[N];
int T, n, m;
bool flag;
string s;

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

signed main()
{
    ios;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        p[i] = i;

    int res = 0;
    while (m--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n || y > n)
            res++;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
