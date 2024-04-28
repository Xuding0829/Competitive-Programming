#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N], p[N];
int n, m;

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M')
            p[find(a)] = find(b);
        else
            puts(find(a) == find(b) ? "Yes" : "No");
    }
    return 0;
}