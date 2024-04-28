#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
using namespace std;

const int N = 2e5 + 100;

int n, m;
int b[N];

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(b, 0, (n + 1) * 4);
        // 注意超时
        for (int i = 1, x; i <= n; i++)
        {
            cin >> x;
            int l = max(1, i - x + 1);
            int r = i;
            // 对于第i次操作，数组中一共有i个元素，此时要求【i- x + 1, i】的元素都为1
            b[l]++;
            b[r + 1]--;
            // 差分 要求这段区间上的数都+1
        }
        for (int i = 1; i <= n; i++)
            b[i] += b[i - 1];
        // b数组前缀和即是原数组

        for (int i = 1; i <= n; i++)
            cout << !!b[i] << ' ';
        // 输出01串，例如 6 -> 0 -> 1
        puts("");
    }
    return 0;
}
