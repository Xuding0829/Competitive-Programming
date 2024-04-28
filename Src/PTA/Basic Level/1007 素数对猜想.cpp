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
    int n, cnt = 0;
    int i = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n - 2; i++)
        if (isprime(i) && isprime(i + 2))
            cnt++;
    printf("%d\n", cnt);
    return 0;
}