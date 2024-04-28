#include <stdio.h>
const int maxn = 1e6 + 10;
int a[maxn] = {0}, b[maxn] = {0};
int n, m;

void insert(int l, int r, int v)
{
    b[l] += v;
    b[r + 1] -= v;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    while (m--)
    {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        insert(l, r, v);
    }
    for (int i = 1; i <= n; i++)
        b[i] = b[i] + b[i - 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    return 0;
}