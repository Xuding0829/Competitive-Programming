#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int x = 0;
    std::stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(a[i]);
        while (st.top() == b[x])
        {
            st.pop();
            x++;
            if (st.empty())
                break;
        }
    }

    if (st.empty())
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}