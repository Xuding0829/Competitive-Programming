#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int kase = 0;
    while (t--)
    {
        long long int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", ++kase, a + b > c ? "true" : "false");
    }
    return 0;
}