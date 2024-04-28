#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (1 << 20) + 1;
int prime[N], cnt;
bool st[N];
int n, m;
int minp[N]; // minp[i] 存储 i 的最小质因数

void get_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            prime[cnt++] = i;
            minp[i] = i;
        }
        for (int j = 0; prime[j] <= n / i; j++)
        {
            int t = prime[j] * i;
            st[t] = true;
            minp[t] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

signed main()
{
    get_prime(N - 1);

    int x;
    while (cin >> x)
    {
        int sum[30];
        int k = 0, totol = 0;
        // k是质因数的个数
        // toltl = a1 + a2 + a3 + a4 + ....
        // 分解质因数
        while (x > 1)
        {
            int p = minp[x];
            sum[k] = 0;
            while (x % p == 0)
            {
                sum[k]++;
                totol++;
                x /= p;
            }
            k++;
        }

        int res = 1; // res = (a1 + .... + an)!/ a1! / a2! / ... / an!
        for (int i = 1; i <= totol; i++)
            res *= i;

        for (int i = 0; i < k; i++)
            for (int j = 1; j <= sum[i]; j++)
                res /= j;

        cout << totol << ' ' << res << endl;
    }
    return 0;
}