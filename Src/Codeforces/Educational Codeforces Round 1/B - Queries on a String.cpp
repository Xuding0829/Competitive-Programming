#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    while (n--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--, r--;
        int len = r - l + 1;
        k %= len;

        if (!k)
            continue;

        std::string s1 = s.substr(0, l);
        std::string s2 = s.substr(l, len);
        std::string s3 = s.substr(r + 1);

        std::string t = s2.substr(len - k);
        s2.erase(len - k);
        s2 = t + s2;

        s = s1 + s2 + s3;
    }

    std::cout << '\n';
    std::cout << s << '\n';

    return 0;
}