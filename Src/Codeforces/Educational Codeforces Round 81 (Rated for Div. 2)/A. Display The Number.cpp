#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int a[N];
int T, n, m;
string s;
bool flag;

void solve()
{
    cin >> n;
    if (n % 2 == 1)
        flag = 1;
    while (n)
    {
        if (flag)
        {
            n -= 3;
            cout << 7;
            flag = 0;
        }
        if (n >= 2)
        {
            cout << 1;
            n -= 2;
        }
    }
    cout << endl;
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
