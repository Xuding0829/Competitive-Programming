#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = 1e5 + 100;

    std::vector<int> a(5);
    for (int i = 0; i < 4; i++)
        std::cin >> a[i];

    int d;
    std::cin >> d;

    std::set<int> st;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= d / a[i]; j++)
            st.insert(j * a[i]);
    std::cout << st.size() << '\n';

    return 0;
}