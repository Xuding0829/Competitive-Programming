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

void solve()
{
    vector<string> str;
    string s;
    while (cin >> s)
    {
        str.push_back(s);
    }
    cout << str[str.size() - 1];
    for (int i = str.size() - 2; i >= 0; i--)
        cout << " " << str[i];
}

int main()
{
    ios;
    solve();
    return 0;
}
