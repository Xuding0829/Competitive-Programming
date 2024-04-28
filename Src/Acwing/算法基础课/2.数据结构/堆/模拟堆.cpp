#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int,int>PII;

const double eps = 1e-6;
const int mod=1e9+7;
const int N = 1e5 + 10;


int h[N], ph[N], hp[N], cnt;

int a[N];
int T,n,m;
bool flag;
string s;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int x)
{
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t])
        t = 2 * x + 1;
    if (t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

void up(int x)
{
    while (x / 2 && h[x] < h[x / 2])
    {
        heap_swap(x, x / 2);
        x >>= 1;
    }
}

signed main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        int k, x;

        if (op[0] == 'I')
        {
            cin >> x;
            cnt++, m++;
            ph[m] = cnt;
            hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, cnt--);
            down(1);
        }
        else if (op[0] == 'D')
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, cnt--);
            up(k);
            down(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}
