#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    // 二分找到最大的小于当前数x的数c
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> st;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    st.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] > st.back())
            st.push_back(a[i]);
        else
            *lower_bound(st.begin(), st.end(), a[i]) = a[i];

    std::cout << st.size() << '\n';
    return 0;
}
/*
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int len = 0;
    std::vector<int> f(n + 1);
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            // 寻找小于a[i]的最大的数
            int mid = l + r + 1 >> 1;
            if (f[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        f[l + 1] = a[i];
        len = std::max(len, l + 1);
    }
    std::cout << len << '\n';
    return 0;
}
*/