#include <stdio.h>
#include <string.h>

int main()
{
    const int maxn = 1001;
    char a[maxn];
    int b[maxn];
    gets(a);
    int sum = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        sum += a[i] - 48;
    }
    int temp = sum, flag = 1;
    int j = 0;
    while (temp > 0)
    {
        b[j++] = temp % 10;
        temp = temp / 10;
    }
    for (--j; j >= 0; j--)
    {
        switch (b[j])
        {
        case 1:
            printf("yi");

            break;
        case 2:
            printf("er");

            break;
        case 3:
            printf("san");

            break;
        case 4:
            printf("si");

            break;
        case 5:
            printf("wu");

            break;
        case 6:
            printf("liu");

            break;
        case 7:
            printf("qi");

            break;
        case 8:
            printf("ba");

            break;
        case 9:
            printf("jiu");

            break;
        default:
            printf("ling");
        }
        if (j != 0)
            printf(" ");
    }
    printf("\n"); // 检测末尾是否有空格输出
    return 0;
}