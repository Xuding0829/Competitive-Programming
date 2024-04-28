#include <bits/stdc++.h>

using i64 = long long;

int n;

bool check(int a, int b, std::string s, std::vector<int> &res)
{
    res[0] = a, res[1] = b;
    // 先确定前两个的身份
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == 'o')
        {
            if (res[i])
                res[i + 1] = res[i - 1];
            else
                res[i + 1] = !res[i - 1];
        }
        else
        {
            if (res[i])
                res[i + 1] = !res[i - 1];
            else
                res[i + 1] = res[i - 1];
        }
    }

    if (s[0] == 'o')
    {
        if (res[0])
        {
            if (res[1] != res[n - 1])
                return false;
        }
        else
        {
            if (res[1] == res[n - 1])
                return false;
        }
    }
    else
    {
        if (res[0])
        {
            if (res[1] == res[n - 1])
                return false;
        }
        else
        {
            if (res[1] != res[n - 1])
                return false;
        }
    }

    if (s[n - 1] == 'o')
    {
        if (res[n - 1])
        {
            if (res[0] != res[n - 2])
                return false;
        }
        else
        {
            if (res[0] == res[n - 2])
                return false;
        }
    }
    else
    {
        if (res[n - 1])
        {
            if (res[0] == res[n - 2])
                return false;
        }
        else
        {
            if (res[0] != res[n - 2])
                return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> n >> s;

    std::vector<int> res(n);

    int a[4] = {1, 1, 0, 0}, b[4] = {1, 0, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int x = a[i], y = b[i];
        if (check(x, y, s, res))
        {
            for (int i = 0; i < n; i++)
            {
                if (res[i])
                    std::cout << 'S';
                else
                    std::cout << 'W';
            }
            return 0;
        }
    }
    std::cout << -1 << '\n';

    return 0;
}