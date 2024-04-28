#include <bits/stdc++.h>

using i64 = long long;

const int N = 310;

int r, c;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
std::vector<std::vector<int>> h(N, std::vector<int>(N));
std::vector<std::vector<int>> f(N, std::vector<int>(N, -1));

int dp(int x, int y)
{
    int &v = f[x][y];
    if (v != -1)
        return v;
    v = 1;

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= r && b >= 1 && b <= c && h[a][b] < h[x][y])
            v = std::max(v, dp(a, b) + 1);
    }
    return v;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            std::cin >> h[i][j];

    int res = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            res = std::max(res, dp(i, j));
    std::cout << res << "\n";

    return 0;
}