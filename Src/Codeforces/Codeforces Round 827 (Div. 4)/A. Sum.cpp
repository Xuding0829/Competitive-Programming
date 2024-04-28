#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a[3];
        for (int i = 0; i < 3; i++)
            scanf("%d", &a[i]);
        if (a[0] + a[1] == a[2] || a[1] + a[2] == a[0] || a[0] + a[2] == a[1])
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
