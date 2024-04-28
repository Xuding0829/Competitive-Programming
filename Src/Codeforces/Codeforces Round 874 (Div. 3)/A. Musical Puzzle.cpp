#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::set<std::string> st;
    for (int i = 1; i < n; i++)
    {
        std::string t;
        t += s[i - 1];
        t += s[i];
        st.insert(t);
    }
    std::cout << st.size() << '\n';
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