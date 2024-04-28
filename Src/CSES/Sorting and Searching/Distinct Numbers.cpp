#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::set<int> st;
    for (int i = 0, x; i < n; i++)
        std::cin >> x, st.insert(x);
    std::cout << st.size() << '\n';

    return 0;
}