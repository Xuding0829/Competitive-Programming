#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) // 特判闰年
        day[2] = 29;                                // 闰年2月29天
    printf("%d", day[m]);
    return 0;
}