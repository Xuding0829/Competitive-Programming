#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 2e6 + 100;

int v[20], a[N];
int T, n, m;
bool flag;
string s;

void solve()
{
    cin >> n;
    cin >> s;

    for (int i = 1; i <= 9; i++)
        cin >> v[i];

    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] - '0';

    for (int i = 0; i < n; i++)
    {
        if (v[a[i]] > a[i])
        {
            a[i] = v[a[i]];
            i++;
            while (v[a[i]] >= a[i] && i < n)
            {
                a[i] = v[a[i]];
                i++;
            }
            break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

int main()
{
    ios;
    solve();
    return 0;
}
