#include <cstdio>
#include <iostream>
#include <cmath>

const double pi = 3.141593;

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("I love Luogu!\n");
        return 0;
    }
    if (n == 2)
    {
        printf("%d %d", 2 + 4, 10 - 2 - 4);
        return 0;
    }
    if (n == 3)
    {
        printf("%d\n%d\n%d\n", 14 / 4, 14 / 4 * 4, 14 - 14 / 4 * 4);
        return 0;
    }
    if (n == 4)
    {
        printf("%.3lf\n", 166.667);
        return 0;
    }
    if (n == 5)
    {
        printf("%d\n", (260 + 220) / (12 + 20));
        return 0;
    }
    if (n == 6)
    {
        std::cout << 10.8167 << std::endl;
        return 0;
    }
    if (n == 7)
    {
        printf("%d\n%d\n%d\n", 100 + 10, 100 + 10 - 20, 0);
        return 0;
    }
    if (n == 8)
    {
        printf("31.4159\n78.5398\n523.599\n");
        return 0;
    }
    if (n == 9)
    {
        printf("%d\n", (((1 + 1) * 2 + 1) * 2 + 1) * 2);
        return 0;
    }
    if (n == 10)
    {
        printf("%d\n", 9);
        return 0;
    }
    if (n == 11)
    {
        printf("33.3333\n");
        return 0;
    }
    if (n == 12)
    {
        printf("%d\n%c\n", 'M' - 'A' + 1, 'A' + 18 - 1);
        return 0;
    }
    if (n == 13)
    {
        printf("%d\n", 16);
        return 0;
    }
    if (n == 14)
    {
        printf("%d\n", 50);
        return 0;
    }
}