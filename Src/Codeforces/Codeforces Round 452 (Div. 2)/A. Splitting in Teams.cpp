#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int res = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x % 2)
            cnt1++;
        else
            cnt2++;
    }

    if (cnt1 && cnt2)
        res += std::min(cnt1, cnt2);
    cnt1 -= res;
    cnt2 -= res;
    res += cnt1 / 3;

    std::cout << res << '\n';
    return 0;
}