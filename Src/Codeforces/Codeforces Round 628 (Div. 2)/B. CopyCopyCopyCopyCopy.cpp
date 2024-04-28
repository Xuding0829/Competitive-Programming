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
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
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
