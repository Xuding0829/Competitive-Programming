#include <stdio.h>
const int maxn = 1e6 + 1;
int a[maxn], s[maxn];
int main()
{
    int n, t;
    a[0] = 0;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    while (t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}