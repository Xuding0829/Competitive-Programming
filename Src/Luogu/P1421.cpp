#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int money = a * 10 + b;
    int price = 19;
    printf("%d", money / price);
    return 0;
}