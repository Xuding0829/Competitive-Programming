#include<bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 sum = 0, mother = 0, month = 1;
    bool flag = false;
    for (int i = 1, x; i <= 12; i++)
    {
        sum += 300;
        std::cin >> x;
        sum -= x;
        if(sum < 0)
        {
            flag = true;
            month = i;
            break;
        }
        mother += sum / 100;
        sum %= 100;
    }

    std::cout << (flag ? -month : sum + mother * 120) << '\n';

    return 0;
}