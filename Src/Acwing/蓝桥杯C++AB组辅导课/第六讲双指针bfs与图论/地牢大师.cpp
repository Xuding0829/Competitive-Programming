#include <bits/stdc++.h>

using namespace std;

const int N = 110;
char g[N][N][N];
int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int l, r, c;
int dis[N][N][N];
struct Point
{
    int x, y, z;
} point[N * N * N];

queue<Point> q;

int bfs(Point st, Point ed)
{
    q.push(st);

    memset(dis, -1, sizeof(dis));
    dis[st.x][st.y][st.z] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int A = t.x + dx[i];
            int B = t.y + dy[i];
            int C = t.z + dz[i];

            if (A < 0 || A >= l || B < 0 || B >= r || C < 0 || C >= c)
                continue;
            if (g[A][B][C] == '#')
                continue;
            if (dis[A][B][C] != -1)
                continue;
            dis[A][B][C] = dis[t.x][t.y][t.z] + 1;
            Point tmp = {A, B, C};
            q.push(tmp);
        }
    }

    return dis[ed.x][ed.y][ed.z];
}

signed main()
{
    while (scanf("%d%d%d", &l, &r, &c) != EOF && l && r && c)
    {
        Point st, ed;
        // L,R,C 分别表示地牢层数，以及每一层地牢的行数和列数。
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
            {
                scanf("%s", g[i][j]);
                for (int k = 0; k < c; k++)
                {
                    if (g[i][j][k] == 'S')
                        st = {i, j, k};
                    else if (g[i][j][k] == 'E')
                        ed = {i, j, k};
                }
            }

        int distance = bfs(st, ed);

        if (distance != -1)
            printf("Escaped in %d minute(s).\n", distance);
        else
            puts("Trapped!");
    }
    return 0;
}