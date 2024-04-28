#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    getline(std::cin, s);

    std::set<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            st.insert(s[i]);
    }

    std::cout << st.size() << '\n';

    return 0;
}