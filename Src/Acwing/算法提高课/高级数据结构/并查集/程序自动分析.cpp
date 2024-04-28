#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m;
int p[N];
unordered_map<int, int> S;

struct Query
{
    int x, y, e;
} query[N];

int get(int x)
{
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve()
{
    n = 0;
    S.clear();
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, e;
        scanf("%d%d%d", &x, &y, &e);
        query[i] = {get(x), get(y), e};
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
        if (query[i].e == 1)
        {
            int pa = find(query[i].x), pb = find(query[i].y);
            p[pa] = pb;
        }

    bool has_conflict = false;
    for (int i = 0; i < m; i++)
        if (query[i].e == 0)
        {
            int pa = find(query[i].x), pb = find(query[i].y);
            if (pa == pb)
            {
                has_conflict = true;
                break;
            }
        }

    std::cout << (has_conflict ? "NO\n" : "YES\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }

    return 0;
}