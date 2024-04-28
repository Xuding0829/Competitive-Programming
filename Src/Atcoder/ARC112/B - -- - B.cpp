#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

int B, C;
void calc(int C, int &x, int &y)
{
    if (!C) // c = 0
        x = B, y = B;
    else if (C & 1)
    {
        int t = C / 2;
        x = -B - t;
        y = -B + t;
        // c为奇数可执行一次1操作，（c - 1）/ 2次操作
        // 先执行1操作，-->    -B - (c - 1) / 2 = -B - c / 2
        // 最后执行1操作， -->    -(B - (c - 1) / 2) = -B + c / 2
    }
    else
    {
        int t = C / 2;
        x = B - t;
        y = B + t - 1;
        // c 为偶数，可以全执行1操作 B -->  B - c / 2
        // 或者先1操作，后2操作，最后在进行1操作 B + (C - 2) / 2
    }
}

signed main()
{

    cin >> B >> C;
    int a, b, c, d;
    calc(C, a, b);
    calc(C - 1, c, d);
    cout << (b - a + 1) + (d - c + 1) - max(0ll, min(b, d) - max(a, c) + 1) << endl;
    return 0;
}