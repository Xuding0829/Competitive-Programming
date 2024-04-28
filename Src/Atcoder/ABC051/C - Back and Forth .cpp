#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    for (int i = 0; i < ty - sy; i++)
        std::cout << 'U';
    for (int i = 0; i < tx - sx; i ++)
        std::cout << 'R';
    // 到达了终点
    for (int i = 0; i < ty - sy; i++)
        std::cout << 'D';
    for (int i = 0; i < tx - sx; i++)
        std::cout << 'L';
    // 回到了起点

    std::cout << 'L';
    for (int i = 0; i <= ty - sy; i++)
        std::cout << 'U';
    for (int i = 0; i <= tx - sx; i++)
        std::cout << 'R';
    std::cout << 'D';
    // 到达终点
    std::cout << 'R';
    for (int i = 0; i <= ty - sy; i++)
        std::cout << 'D';
    for (int i = 0; i <= tx - sx; i++)
        std::cout << 'L';
    std::cout << 'U';
    // 回到起点
    return 0;
}