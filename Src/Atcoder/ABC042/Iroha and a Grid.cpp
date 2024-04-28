#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

const int N = 2e5 + 100;
const int mod = 1e9 + 7;
int f[N];
int res;

// 题目大意： 从左上角到右下角，不经过a*b区域的走法有多少种
// 考虑从(1，1)-->(h-a+1, b+1)...(h-a+1,w)
// 在考虑从(h-a+1, b+1)...(h-a+1,w)--> (h, w);
// 对对应的方案数相乘后累加即解
// 代码实现难点在于求组合数

int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

// 卢卡斯定理求解超时 -- > 阶乘预处理

// int c(int a, int b)
// {
//     if (b > a)
//         return 0;

//     int res = 1;
//     for (int i = 1, j = a; i <= b; i++, j--)
//     {
//         res = res * j % mod;
//         res = res * qmi(i, mod - 2) % mod;
//     }
//     return res;
// }

// int lucas(int a, int b)
// {
//     if (a < mod && b < mod)
//         return c(a, b);
//     else
//         return c(a % mod, b % mod) * c(a / mod, b / mod);
// }

void init()
{
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % mod;
}

// c(n, m) = n! (m!)^-1(n-m)!^-1;
int c(int n, int m)
{
    int a = f[n];
    int b = (f[m] * f[n - m]) % mod;
    return (a * qmi(b, mod - 2)) % mod;
}

signed main()
{
    init();

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    for (int i = b + 1; i <= w; i++)
    {
        int tmp = c(h - a + i - 2, h - a - 1) * c(a + w - i - 1, w - i) % mod;
        res = (res % mod + tmp % mod) % mod;
    }

    cout << res % mod << endl;
    return 0;
}
