#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
int T, n, m, k;
int a[N];

int main()
{
    int sum = 0;
    int sum2 = 0;

    cin >> n >> k;
    while (k--)
    {
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
            cin >> a[i];

        // 判断是否连续
        if (a[1] == 1)
        {
            int flag = 0;
            for (int i = 1; i <= t; i++)
            {
                if (a[i] != i)
                {
                    flag = i;
                    break;
                }
            }
            // 如果不连续
            if (flag)
            {
                sum += (t - flag + 1);
                sum2 += (t - flag + 1);
            }
        }
        else
        {
            sum += t;
            sum2 += t - 1;
        }
    }

    cout << sum + sum2 << endl;
    return 0;
}
