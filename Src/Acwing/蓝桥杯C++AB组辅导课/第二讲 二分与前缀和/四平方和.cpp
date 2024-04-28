#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

using namespace std;

const int N = 6e6 + 100;

int n, m;
int C[N], D[N];
/*
// 暴力写法1
for (int a = 0; a * a <= n; a++)
    for (int b = a; a * a + b * b <= n; b++)
        for (int c = b; a * a + b * b + c * c <= n; c++)
        {
            int t = n - a * a - b * b - c * c;
            int d = sqrt(t);
            if (d * d == t)
            {
                cout << a << b << c << d << endl;
                return 0;
            }
        }
*/

// 类似于哈希表的做法

/*
signed main()
{
    scanf("%d", &n);
    // 通过分析时间复杂度，得出最多枚举两个数, 因此用空间换时间
    // 预处理c^2 + d^2 的和
    memset(C, -1, sizeof(C));
    for (int c = 0; c * c <= n; c++)
        for (int d = c; c * c + d * d <= n; d++)
        {
            int s = c * c + d * d;
            if (C[s] == -1) // 保证C、D数组存储的字典序是最小的
            {
                C[s] = c;
                D[s] = d;
            }
        }

    for (int a = 0; a * a <= n; a++)
        for (int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            // 查表，如果存在输出
            if (C[t] != -1)
            {
                printf("%d %d %d %d\n", a, b, C[t], D[t]);
                return 0;
            }
        }
    return 0;
}
*/

// 二分写法

struct sum
{
    int s, c, d;
    bool operator<(const sum &t)
    {
        if (s != t.s)
            return s < t.s;
        if (d != t.c)
            return c < t.c;
        return d < t.d;
    }
} s[N];

signed main()
{
    cin >> n;
    for (int c = 0; c * c <= n; c++)
        for (int d = c; c * c + d * d <= n; d++)
        {
            int sum = c * c + d * d;
            s[m++] = {sum, c, d};
        }

    sort(s, s + m);

    for (int a = 0; a * a <= n; a++)
        for (int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;
            // 二分查找
            while (l < r)
            {
                int mid = l + r >> 1;

                if (s[mid].s < t)
                    l = mid + 1;
                else
                    r = mid;
            }

            if (s[r].s == t)
            {
                cout << a << ' ' << b << ' ' << s[r].c << ' ' << s[r].d << endl;
                return 0;
            }
        }

    return 0;
}