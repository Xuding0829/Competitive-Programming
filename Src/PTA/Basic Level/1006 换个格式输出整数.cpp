#include <stdio.h>
int main()
{
    int temp, a[4] = {0}, i = 0;
    scanf("%d", &temp);
    while (temp > 0)
    {
        a[++i] = temp % 10;
        temp = temp / 10;
    }
    for (int j = 0; j < a[3]; j++)
        printf("B");
    for (int j = 0; j < a[2]; j++)
        printf("S");
    for (int j = 1; j <= a[1]; j++)
        printf("%d", j);
    return 0;
}