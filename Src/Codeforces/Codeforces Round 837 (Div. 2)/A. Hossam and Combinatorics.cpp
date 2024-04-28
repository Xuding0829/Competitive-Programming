#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef long double lb;

const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e6;
const int mod = 1e9 + 7;
int T, n, m;
int a[N];
int b[N];

void solve()
{
    ll cnt = 0;
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    if (mp.size() == 1)
        cout << n * (n - 1) << endl;
    else
    {
        ll cnt = mp[v[0]] * mp[v[n - 1]] * 2;
        cout << cnt << endl;
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
