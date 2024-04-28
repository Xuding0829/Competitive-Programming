#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (!st.count(x))
            st.insert(x * m);
    }
    cout << st.size() << endl;
    return 0;
}