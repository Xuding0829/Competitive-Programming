#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

bool cmp(int x, int y)
{
    return x > y;
}

signed main()
{
    cin >> n >> m;
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    sort(a, a + n, cmp);

    int tmp = ceil(sum * 1.0 / (4 * m));
    for (int i = 0; i < m; i++)
        if (a[i] >= tmp)
            cnt++;

    puts(cnt >= m ? "Yes" : "No");
    return 0;
}