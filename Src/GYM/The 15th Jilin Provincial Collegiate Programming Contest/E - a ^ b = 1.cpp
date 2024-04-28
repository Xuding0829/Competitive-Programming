#include <bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

const int mod197 = 1e9 + 7;
const int mod353 = 998244353;
const int N = 2e5 + 100;

int n, m, k, q;
int a[N];

void solve()
{
    cin >> n;
    set<int> st;
    st.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (st.count(a[i] ^ 1))
        {
            ans = true;
            break;
        }
    }
    puts(ans ? "Yes" : "No");
}

signed main()
{
    ios;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
