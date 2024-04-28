#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    std::vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    std::function<std::vector<int>(std::vector<int>, std::vector<int>)> Add = [&](std::vector<int> a, std::vector<int> b)
    {
        if (a.size() < b.size())
            return Add(b, a);
        int t = 0;
        std::vector<int> c;
        for (int i = 0; i < a.size(); i++)
        {
            t += a[i];
            if (i < b.size())
                t += b[i];
            c.push_back(t % 10);
            t /= 10;
        }
        if (t)
            c.push_back(t);
        return c;
    };

    std::vector<int> res;
    res = Add(A, B);

    for (int i = res.size() - 1; i >= 0; i--)
        std::cout << res[i];

    return 0;
}