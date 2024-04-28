#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;
int a[N];

signed main()
{
    int n;
    long double s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long double res = 0;
    long double ave = s / n;

    for (int i = 0; i < n; i++)
    {
        double cur = s / (n - i);
        if (a[i] < cur)
            cur = a[i];
        s -= cur;
        res += (cur - ave) * (cur - ave);
    }

    printf("%.4llf\n", sqrt(res / n));
    return 0;
}