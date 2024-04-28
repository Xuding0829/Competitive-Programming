#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
int a[N];
set<int> st;

bool check(int x)
{
    int t = x;
    while (x)
    {
        t = x % 10;
        if (st.count(t))
            return false;
        x /= 10;
    }
    return true;
}

signed main()
{
    int n, k;
    cin >> n >> k;

    st.clear();

    for (int i = 0, x; i < k; i++)
    {
        cin >> x;
        st.insert(x);
    }

    for (int i = n;; i++)
    {
        if (check(i))
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}