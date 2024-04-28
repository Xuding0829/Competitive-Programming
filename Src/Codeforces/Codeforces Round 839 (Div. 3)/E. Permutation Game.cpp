#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int a = 0, b = 0, c = 0;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        if (x == i)
            a++;
        else if (x == n - i + 1)
            b++;
        else
            c++;
    }

    if (b + c <= a)
        std::cout << "First\n";
    else if (a + c < b)
        std::cout << "Second\n";
    else
        std::cout << "Tie\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}