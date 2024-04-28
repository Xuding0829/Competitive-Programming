#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
int a[N];
int num[25];

bool isprime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}

int get_num(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}

signed main()
{
    for (int i = 0; i < 25; i++)
        num[i] = i;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int op = 0; op < 1 << n; op++)
        if (get_num(op) == k)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                if (op >> i & 1)
                    sum += a[i];
            if (isprime(sum))
                res++;
        }
    cout << res << endl;
    return 0;
}