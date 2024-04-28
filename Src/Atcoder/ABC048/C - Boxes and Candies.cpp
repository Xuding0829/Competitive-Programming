#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;
int res;
bool success = true;

signed main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        int t = a[i] + a[i - 1] - m;
        if (t > 0)
            res += t, a[i] -= t;
    }

    // for (int i = 1; i <= n; i++)
    //     cout << "a" << i << " " << a[i] << endl;

    cout << res << endl;

    return 0;
}

/*

signed main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
        if (a[i] + a[i - 1] < m)
        {
            success = false;
            break;
        }
    // 注意：Any two neighboring boxes contain at most x candies in total。 此处不可以直接退出

    if (!success)
        puts("0");
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int t = a[i] + a[i - 1] - m;
            if (t >= 0)
                res += t, a[i] -= t;
        }

        cout << res << endl;

        for (int i = 1; i <= n; i++)
            cout << "a" << i << " " << a[i] << endl;
    }
    return 0;
}*/