#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100, P = 131;//P = 131

int a[N];
int T, n, m;
char str[N];
ULL p[N], h[N];
//原理：扩大至相同位数做差
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

signed main()
{
    cin >> n >> m;
    scanf("%s", str + 1);
    // 预处理
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
