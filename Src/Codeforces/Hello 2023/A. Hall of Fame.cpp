#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::set<char> st;
    for (auto i : s)
        st.insert(i);
    if (st.size() == 1)
        std::cout << -1 << '\n';
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L' && s[i + 1] == 'R')
            {
                std::cout << i + 1 << '\n';
                return;
            }
        }
        std::cout << 0 << '\n';
    }
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