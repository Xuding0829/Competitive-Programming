#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
char g[N][N];
bool st[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
queue<PII> q;

void bfs(int a, int b, int &totol, int &bound)
{
    q.push({a, b});
    st[a][b] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        totol++; // 队列存储的实际上是陆地
        bool is_bound = false;
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= n)
                continue; // 出界
            if (st[x][y])
                continue; // 已被寻找
            if (g[x][y] == '.')
            {
                is_bound = true; // 边缘是海
                continue;
            }
            q.push({x, y});  // x,y 是陆地
            st[x][y] = true; // 标记已找
        }
        if (is_bound)
            bound++;
    }
}

signed main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!st[i][j] && g[i][j] == '#')
            {
                int totol = 0, bound = 0; // totol 用于记录陆地的数量， bound 用于记录陆地中边缘是海的数量
                bfs(i, j, totol, bound);
                if (totol == bound) // 如果陆地全是边缘地带就会被淹没，res++
                    res++;
            }
        }

    printf("%d\n", res);
    return 0;
}