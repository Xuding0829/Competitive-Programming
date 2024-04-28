#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 100;
const int mod197 = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m, k, q;
int a[N];

set<int> st;
void solve()
{
    for (int i = 0, x; i < 3; i++)
    {
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
}

signed main()
{
    ios;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
