#include <stdio.h>
int isprime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    int m, n, cnt = 0;
    int a[110000];
    a[0] = 2;
    a[1] = 3;
    int k = 3, j = 2;
    scanf("%d%d", &m, &n);
    for (int i = 2; i <= 110000; i++)
    {
        if (isprime(++k))
        {
            a[j++] = k;
        }
    }
    for (int i = m; i <= n; i++)
    {
        printf("%d", a[i - 1]);
        ++cnt;
        if (i != n)
        {
            if (cnt != 10)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
                cnt = 0;
            }
        }
    }
    return 0;
}