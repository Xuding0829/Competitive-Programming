#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N];
int T, n, m;
bool flag;
string s;

int son[N][26], cnt[N], idx;
char str[N];

void insert(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

signed main()
{
    cin >> T;
    while (T--)
    {
        char op;
        cin >> op;
        if (op == 'I')
        {
            cin >> s;
            insert(s);
        }
        else
        {
            cin >> s;
            cout << query(s) << endl;
        }
    }
    return 0;
}
