#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N] = {0};

int T, n, m;

void solve()
{
    cin >> n;
    int sum = 0;
    int b[100001] = {0};
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    if (sum % 2 == 0)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0) // a[i] is odd ;
            {
                while (a[i] % 2 == 1)
                {
                    a[i] = a[i] / 2;
                    b[i]++;
                }
            }
            else // a[i] is even ;
            {
                while (a[i] % 2 == 0)
                {
                    a[i] = a[i] / 2;
                    b[i]++;
                }
            }
        }
        sort(b, b + n);
        cout << b[0] << endl;
    }
}

int main()
{
    ios;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
