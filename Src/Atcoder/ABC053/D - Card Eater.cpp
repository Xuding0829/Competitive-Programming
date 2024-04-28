#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::set<i64> st;
    for (int i = 0, x; i < n; i++)
        std::cin >> x, st.insert(x);

    if (st.size() & 1)
        std::cout << st.size();
    else
        std::cout << st.size() - 1;

    return 0;
}