#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #define int long long

using namespace std;

const int N = 10;

int n, m;
char g[N][N], backup[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {1, 0, -1, 0, 0};

void turn(int x, int y) // turn函数实现改变四周灯的暗灭情况
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5)
            continue; // 越界不计算
        g[a][b] ^= 1; //  异或计算化简
    }
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 5; i++)
            cin >> g[i];

        int res = 10;
        // 第一行一个5个数，每个数可以为1 或 0，共有2^5种结果
        for (int op = 0; op < 32; op++)
        {
            int step = 0;
            // backup数组用于存储初始数组g
            memcpy(backup, g, sizeof(g));

            for (int i = 0; i < 5; i++)
            {
                if (op >> i & 1)
                {
                    // op的i位是1就按，不管输入是什么
                    step++;
                    turn(0, i);
                }
            }
            // op枚举第一行的操作数，注意此处不管第一行的输入的数据是什么，就根据op各个位模拟

            // 枚举每一行，若为0，通过下一行同列按钮，实现改变
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                {
                    if (g[i][j] == '0')
                    {
                        step++;
                        turn(i + 1, j);
                    }
                }

            // 最后一行的状态由前面几行确定且无法更改，判断最后一行是否有亮着灯，确定答案。若无，更新res，若有，则不可能，res 不变仍然为10
            bool dark = false;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            if (!dark)
                res = min(res, step);

            memcpy(g, backup, sizeof(backup));
        }

        if (res > 6)
            res = -1;
        cout << res << endl;
    }

    return 0;
}