#include <cstdio>
#include <numeric>
using namespace std;
int n, a[1001];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    return !printf("%d", accumulate(a + 1, a + n + 1, 0)); // 调用STL
}