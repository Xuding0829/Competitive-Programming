#include <stdio.h>
int main()
{
    int a, b, c;
    int num[10] = {0};
    int cnt = 0;
    int i;
    for (a = 123; a <= 333; a++)
    {
        cnt = 0;
        b = a * 2;
        c = a * 3;
        num[a / 100] = 1;
        num[a / 10 % 10] = 1;
        num[a % 10] = 1;
        num[b / 100] = 1;
        num[b / 10 % 10] = 1;
        num[b % 10] = 1;
        num[c / 100] = 1;
        num[c / 10 % 10] = 1;
        num[c % 10] = 1;
        for (i = 1; i <= 9; i++)
            if (num[i] == 1)
                cnt++;
        if (cnt == 9)
            printf("%d %d %d\n", a, b, c);
        for (i = 1; i <= 9; i++)
            num[i] = 0;
    }
    return 0;
}