#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 250;
char g[N][N];
int n, m;
int dis[N][N];
PII st, ed;

int bfs(PII st, PII ed)
{
    queue<PII> q;
    q.push(st);

    memset(dis, -1, sizeof(dis));
    dis[st.x][st.y] = 0;

    while (q.size())
    {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (g[a][b] == '#')
                continue;
            if (dis[a][b] != -1)
                continue;
            dis[a][b] = dis[t.x][t.y] + 1;
            q.push({a, b});
        }
    }
    return dis[ed.x][ed.y];
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 'S')
                    st = {i, j};
                else if (g[i][j] == 'E')
                    ed = {i, j};
        int distance = bfs(st, ed);
        if (distance != -1)
            printf("%d\n", distance);
        else
            puts("oop!");
    }

    return 0;
}