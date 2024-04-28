#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 60;

i64 c[N][N]; // longlong

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b;
    std::cin >> n >> a >> b;

    init();

    std::map<i64, int> mp;
    std::vector<i64> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i], mp[v[i]]++;
    std::sort(v.begin(), v.end(), std::greater<i64>());

    i64 sum = 0, cnt = 0;
    for (int i = 0; i < a; i++)
    {
        sum += v[i];
        if (v[i] == v[a - 1])
            cnt++;
    }

    double ave = sum * 1.0 / a;
    std::cout << std::fixed << std::setprecision(6) << ave << '\n';

    i64 res = 0; // res 也要开longlong
    if (cnt < a) // 一开始这里想错了
        res = c[mp[v[a - 1]]][cnt];
    else
        for (int i = a; i <= b && i <= mp[v[a - 1]]; i++)
            res += c[mp[v[a - 1]]][i];
    std::cout << res << '\n';

    return 0;
}