#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> map(1 << N);
    for (int i = 0; i < N; i++)
        map[1 << i] = i;

    std::vector<int> ones(1 << N);
    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            ones[i] += (i >> j) & 1;

    std::string s;
    while (std::cin >> s, s[0] != 'e')
    {
        int init = (1 << N) - 1;
        std::vector<int> row(N, init), col(N, init);
        std::vector cell(N, std::vector<int>(N, init));

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (s[i * N + j] == '.')
                    cnt++;
                else
                {
                    int t = s[i * N + j] - '1';
                    int v = 1 << t;
                    row[i] -= v;
                    col[j] -= v;
                    cell[i / 3][j / 3] -= v;
                }
            }
        }

        // for (int i = 0; i < N; i++)
        //     std::cout << row[i] << " \n"[i == N - 1];

        // for (int i = 0; i < N; i++)
        //     std::cout << col[i] << " \n"[i == N - 1];

        // for (int i = 0; i < 3; i++)
        //     for (int j = 0; j < 3; j++)
        //         std::cout << cell[i][j] << " \n"[j == N - 1];

        std::function<bool(int)> dfs = [&](int cnt)
        {
            if (!cnt)
                return true;

            int min = 10, x, y;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (s[i * N + j] == '.')
                    {
                        int state = row[i] & col[j] & cell[i / 3][j / 3];
                        if (ones[state] < min)
                        {
                            min = ones[state];
                            x = i, y = j;
                        }
                    }
                }
            }

            int state = row[x] & col[y] & cell[x / 3][y / 3];
            for (int i = state; i > 0; i -= i & -i)
            {
                int k = map[i & -i];
                int v = i & -i; // int v = 1 << k;
                s[x * N + y] = k + '1';
                row[x] -= v, col[y] -= v;
                cell[x / 3][y / 3] -= v;

                if (dfs(cnt - 1))
                    return true;

                s[x * N + y] = '.';
                row[x] += v, col[y] += v;
                cell[x / 3][y / 3] += v;
            }
            return false;
        };

        dfs(cnt);
        std::cout << s << '\n';
    }

    return 0;
}