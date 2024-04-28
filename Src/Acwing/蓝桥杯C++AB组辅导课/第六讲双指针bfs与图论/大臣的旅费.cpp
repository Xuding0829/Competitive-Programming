#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int e[N], ne[N], w[N], h[N];
int idx;
int maxu, maxd;

// 数组模拟单链表写法
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int fa, int dis)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        int k = w[i];
        if (j == fa)
            continue;
        if (maxd < dis + k)
        {
            maxu = j;
            maxd = dis + k;
        }
        dfs(j, u, dis + k);
    }
}

signed main()
{
    cin >> n;
    memset(h, -1, sizeof(h));
    int k = n - 1;
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1, 0);
    dfs(maxu, -1, 0);
    cout << maxd * 10 + (maxd + 1ll) * maxd / 2 << endl;
    return 0;
}