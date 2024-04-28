#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 100;
int a[N];
int T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        ll sum = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum *= a[i];
        }

        sum += n - 1;
        cout << sum * 2022 << endl;
    }
    return 0;
}
