#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
int T, n, m, k;
int a[N];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int minn = -1;
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                tmp = a[i - 1] - a[i];
                a[i] = a[i - 1];
                minn = max(minn, tmp);
            }
        }

        if (minn == -1)
            cout << 0 << endl;
        else
        {
            int res = 0;
            while (minn)
            {
                minn /= 2;
                res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}
