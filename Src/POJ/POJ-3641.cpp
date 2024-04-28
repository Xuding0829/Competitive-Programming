#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

bool isprime(int x)
{
    if (x == 2)
        return true;
    else if (x <= 1)
        return false;
    else
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
                return false;
        }
    return true;
}
int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

signed main()
{
    while (cin >> n >> m && n && m)
    {
        if (!isprime(n) && qmi(m, n, n) == m)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}