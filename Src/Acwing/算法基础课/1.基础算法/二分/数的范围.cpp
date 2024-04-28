#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int n, q;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != k)
            printf("-1 -1\n");
        else
        {
            printf("%d ", l);
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (a[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}