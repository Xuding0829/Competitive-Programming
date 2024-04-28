#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::set<int> st;

    int n;
    std::cin >> n;
    while (n--)
    {
        char op;
        int x;
        std::cin >> op >> x;
        if (op == 'I')
            st.insert(x);
        else
            std::cout << (st.count(x) ? "Yes\n" : "No\n");
    }

    return 0;
}