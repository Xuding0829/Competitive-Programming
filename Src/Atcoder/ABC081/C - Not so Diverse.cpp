#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    cin >> n >> m;
    for (int i = 0, x; i < n; i++)
        cin >> x, a[x]++;
    sort(a, a + N, cmp);
    // for (int i = 0; i < 10; i++)
    //     cout << "a" << i << " " << a[i] << endl;
    for (int i = m; i <= n; i++)
        res += a[i];
    cout << res << endl;
    return 0;
}