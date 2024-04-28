#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::set<char> st;
    for (auto i : s)
        if (!st.count(i))
            st.insert(i);
    std::cout << (st.size() % 2 == 0 ? "CHAT WITH HER!\n" : "IGNORE HIM!\n");
    return 0;
}
