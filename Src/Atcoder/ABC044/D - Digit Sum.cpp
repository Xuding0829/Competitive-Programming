#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];

int f(int b, int n)
{
    if (n < b)
        return n;
    else
        return f(b, n / b) + n % b;
}

signed main()
{
    int n, s;
    cin >> n >> s;

    // 讨论 n <= s 的情况
    if (n < s)
    {
        puts("-1");
        return 0;
    }
    else if (n == s)
    {
        cout << n + 1 << endl;
        return 0;
    }

    // n > s
    for (int i = 2; i <= n / i; i++)
    {
        if (f(i, n) == s)
        {
            cout << i << endl;
            return 0;
        }
    }

    n -= s;
    int res = 1e11;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int b = n / i + 1;
            if (f(b, n + s) == s)
                res = min(res, b);
        }
    }

    if (res == 1e11)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}