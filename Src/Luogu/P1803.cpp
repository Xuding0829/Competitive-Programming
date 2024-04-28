#include <bits/stdc++.h>

using i64 = long long;
struct Range
{
    int l, r;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Range> a(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r};
    }

    std::sort(a.begin(), a.end());
    int now = 0, res = 0;
    for (auto [l, r] : a)
    {
        if (now <= l)
            now = r, res++;
    }
    std::cout << res << '\n';
    return 0;
}