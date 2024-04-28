#include <stdio.h>
int main()
{
    int n, m;
    int a[103];
    scanf("%d %d", &n, &m);
    m = m % n;
    getchar();
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[(i + n - m) % n]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}