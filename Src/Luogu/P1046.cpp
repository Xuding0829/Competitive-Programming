#include<bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[10];
    int i, high, sum = 0;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    scanf("%d", &high);
    for (i = 0; i < 10; i++)
        if (a[i] <= high || a[i] <= (high + 30))
            sum++;

    printf("%d", sum);
    return 0;
}