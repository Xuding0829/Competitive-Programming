#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int cnt = 0;
    std::set<int> st;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x < k)
            st.insert(x);
        else if (x == k)
            cnt++;
    }
    std::cout << k - st.size() + cnt << '\n';
    return 0;
}