#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int T, n, m;

struct stu
{
    string name;
    int score;
} a[N];

map<string, int> mp, t;

void solve()
{
    cin >> n;
    int maxn = -100000;
    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].score;
        mp[a[i].name] += a[i].score;
    }

    for (int i = 0; i < n; i++)
        if (mp[a[i].name] > maxn)
            maxn = mp[a[i].name];

    for (int i = 0; i < n; i++)
    {
        t[a[i].name] += a[i].score;

        if (t[a[i].name] >= maxn && mp[a[i].name] == maxn)
        {
            str = a[i].name;
            break;
        }
    }

    cout << str << endl;
}

int main()
{
    ios;

    solve();

    return 0;
}
